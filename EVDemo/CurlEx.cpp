#include "stdafx.h"
#include "curl/curl.h"
#include "EVLiveLock.h"
#include "CurlEx.h"
#include <wininet.h>

#define TIME_CURL_TIMEOUT	(6)							// ��ʱʱ������Ϊ6��;
#define EASYLIVE_KEY		TString(_T("ELive"))			

typedef CURL *(*ex_curl_easy_init)(void);
typedef CURLcode(*ex_curl_easy_setopt)(CURL *curl, CURLoption option, ...);
typedef CURLcode(*ex_curl_easy_perform)(CURL *curl);
typedef void(*ex_curl_easy_cleanup)(CURL *curl);
typedef const char *(*ex_curl_easy_strerror)(CURLcode);
typedef CURLcode(*ex_curl_easy_getinfo)(CURL *curl, CURLINFO info, ...);
typedef void(*ex_curl_slist_free_all)(struct curl_slist *);
typedef curl_slist *(*ex_curl_slist_append)(struct curl_slist *, const char *);

HINSTANCE hCurlDll = NULL;
ex_curl_easy_init ex_pcurl_easy_init = NULL;
ex_curl_easy_setopt ex_pcurl_easy_setopt = NULL;
ex_curl_easy_perform ex_pcurl_easy_perform = NULL;
ex_curl_easy_cleanup ex_pcurl_easy_cleanup = NULL;
ex_curl_easy_strerror ex_pcurl_easy_strerror = NULL;
ex_curl_easy_getinfo ex_pcurl_easy_getinfo = NULL;
ex_curl_slist_free_all ex_pcurl_slist_free_all = NULL;
ex_curl_slist_append ex_pcurl_slist_append = NULL;

typedef std::map<std::string, std::string> MapHeaders;

static TString GetExeDirPath()
{
    TString strExeDirPath;
    if (0 == strExeDirPath.length())
    {
        TCHAR chCurDir[MAX_PATH] = { 0 };
        GetCurrentDirectory(MAX_PATH, chCurDir);
        strExeDirPath.append(chCurDir);
    }
    return strExeDirPath;
}

CCurlEx::CCurlEx()
{
	TString strName = _T("libcurl.dll");
	//TCHAR chCurDir[MAX_PATH] = { 0 };
	//GetCurrentDirectory(MAX_PATH, chCurDir);
	//TString strExePath = GetExeDirPath();
	//SetCurrentDirectory((strExePath + _T("\\dll")).c_str());
	hCurlDll = LoadLibrary(strName.c_str());
	//SetCurrentDirectory(chCurDir);

	if (NULL != hCurlDll)
	{
		ex_pcurl_easy_init = (ex_curl_easy_init)GetProcAddress(hCurlDll, "curl_easy_init");
		ex_pcurl_easy_setopt = (ex_curl_easy_setopt)GetProcAddress(hCurlDll, "curl_easy_setopt");
		ex_pcurl_easy_perform = (ex_curl_easy_perform)GetProcAddress(hCurlDll, "curl_easy_perform");
		ex_pcurl_easy_cleanup = (ex_curl_easy_cleanup)GetProcAddress(hCurlDll, "curl_easy_cleanup");
		ex_pcurl_easy_strerror = (ex_curl_easy_strerror)GetProcAddress(hCurlDll, "curl_easy_strerror");
		ex_pcurl_easy_getinfo = (ex_curl_easy_getinfo)GetProcAddress(hCurlDll, "curl_easy_getinfo");
		ex_pcurl_slist_free_all = (ex_curl_slist_free_all)GetProcAddress(hCurlDll, "curl_slist_free_all");
		ex_pcurl_slist_append = (ex_curl_slist_append)GetProcAddress(hCurlDll, "curl_slist_append");
	}
	else
	{
		DWORD dwErr = GetLastError();
		TString strError = _T("����������ļ�ʧ��!");
	}
}

CCurlEx::~CCurlEx()
{
	if (NULL != hCurlDll)
	{
		FreeLibrary(hCurlDll);
	}
}

TString CCurlEx::GetErrorInfo()
{
	return m_strError;
}

size_t CCurlEx::HttpCallback(void *pStr, size_t iSize, size_t iCount, void *pOutStr)
{
	if (NULL != pOutStr)
	{
		std::string &str = *(std::string *)pOutStr;
		str.append((const char *)pStr, iSize * iCount);
	}
	return iSize * iCount;
}

bool CCurlEx::PostData(OUT std::string& strResult, IN TString strUrl, IN bool bSecurity, IN VecURLHeader& vecHeader)
{
	CURL* pCurl = NULL;
	m_strError.empty();
	try
	{
		// ���libcurl;
		if (NULL == ex_pcurl_easy_init)
		{
			m_strError = _T("����������ļ�ʧ��!");
			throw false;
		}
		else
		{
			pCurl = ex_pcurl_easy_init();
		}

		std::string strAnsi = _T2A(strUrl);
		std::string strUtf8 = TStringTool::AnsiToUtf8(strAnsi.c_str(), strAnsi.length());
		// ����Ŀ���ַ;
		ex_pcurl_easy_setopt(pCurl, CURLOPT_URL, strUtf8.c_str());
		// ֧��zip�ļ�����;
		ex_pcurl_easy_setopt(pCurl, CURLOPT_ACCEPT_ENCODING, "gzip");
		// ����UserAgent;
		//ex_pcurl_easy_setopt(pCurl, CURLOPT_USERAGENT, O_UA);
		// ���ó�ʱʱ��;
		ex_pcurl_easy_setopt(pCurl, CURLOPT_TIMEOUT, TIME_CURL_TIMEOUT);
		// ������֤;
		ex_pcurl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYHOST, 0);
		ex_pcurl_easy_setopt(pCurl, CURLOPT_SSL_VERIFYPEER, FALSE);

		// �����ļ���ȡ�Ļص�����;
		strResult.clear();
		ex_pcurl_easy_setopt(pCurl, CURLOPT_WRITEFUNCTION, HttpCallback);
		ex_pcurl_easy_setopt(pCurl, CURLOPT_WRITEDATA, &strResult);

		curl_slist* pHeaderList = NULL;
		for (int i = 0; i < int(vecHeader.size()); i++)
		{
			std::string strHeader = vecHeader[i].strKey;
			strHeader.append(": ");
			strHeader.append(vecHeader[i].strValue);
			pHeaderList = ex_pcurl_slist_append(pHeaderList, strHeader.c_str());
		}

		if (NULL != pHeaderList)
		{
			ex_pcurl_easy_setopt(pCurl, CURLOPT_HTTPHEADER, pHeaderList);
		}

		//if (bKeepAlive)
		//{
		//	// ������;
		//	pHeadList = ex_pcurl_slist_append(pHeadList, "Connection: keep-alive");
		//	ex_pcurl_easy_setopt(m_pCurl, CURLOPT_HTTPHEADER, pHeadList);
		//}

		// ��ʼ����;
		CURLcode res = ex_pcurl_easy_perform(pCurl);
		if (NULL != pHeaderList)
		{
			ex_pcurl_slist_free_all(pHeaderList);
		}
		if (NULL != pCurl)
		{
			ex_pcurl_easy_cleanup(pCurl);
		}
		if (res != CURLE_OK)
		{
			//m_strError = AflGetLiveError(res).c_str();
			throw false;
		}
	}
	catch (...)
	{
		m_strError = _T("�������δ֪����!");
		return false;
	}

	return true;
}

bool CCurlEx::PostData(OUT JsonValueEx& jsResult, IN TString strUrl, IN bool bSecurity, IN VecURLHeader& vecHeader)
{
	std::string strResult;
	if (!PostData(strResult, strUrl, bSecurity, vecHeader))
	{
		return false;
	}

	jsResult.clear();

	if (strResult.size() == 0u)
	{
		return false;
	}

	try
	{
		// ��������;
		Json::Reader reader;
		if (!reader.parse(strResult, jsResult))
		{
			m_strError = _T("�������ݽ���ʧ�ܣ�");
			throw false;
		}

		std::string strRetVal = jsResult["state"].GetString();
		if ("0" != strRetVal)
		{
			std::string strMess = jsResult["message"].GetString();
			if (0 == strMess.compare(EV_ERROR_PARAM))
			{
				m_strError = _T("��������");
			}
			else
			{
				m_strError = jsResult["message"].GetTString().c_str();
			}

			throw false;
		}
	}
	catch (...)
	{
		/*TString strError;
		strError.Format(_T("����ԭ��: %s, ����URL: %s, ��������: %s \n"), m_strError, strUrl, CA2CT(strResult.c_str()) );
		LOG_ERROR(strError + _T("\n"));*/
		return false;
	}

	return true;
}

bool CCurlEx::DownLoadFile(IN LPCWSTR strUrl, OUT LPCWSTR strLocalPath)
{
	std::string strResult;
	if (!PostData(strResult, strUrl))
	{
		return false;
	}

	FILE* fp = NULL;
	fopen_s(&fp, _T2A(strLocalPath).c_str(), "wb+");
	if (NULL == fp)
	{
		return false;
	}
	size_t nWrite = fwrite(strResult.c_str(), sizeof(char), strResult.size(), fp);
	fclose(fp);
	return true;
}