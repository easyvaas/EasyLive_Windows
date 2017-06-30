#include "stdafx.h"
#include "EVDemoCallBack.h"

CEVDemoCallBack::CEVDemoCallBack()
{
}

CEVDemoCallBack::~CEVDemoCallBack()
{
}

// ���Խ�����ʵ�ַŵ��������cpp��ʵ��;

#if !TEST_PRO
void CEVDemoCallBack::InitSDK_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}
#endif

void CEVDemoCallBack::InitInstance_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::SetParameter_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::GetParameter_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::InitVideoWnd_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::PrepareStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
	else
	{
		// ���ɹ�ʱ,����������ַ;
		CString strPushUrl = CA2CT(strErrInfo);
		SendMessage(AfxGetApp()->GetMainWnd()->GetSafeHwnd(), WM_PREPARESTREAM_CALLBACK, true, LPARAM(strPushUrl.GetString()));
	}
}

void CEVDemoCallBack::StartStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::StopStream_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::SetSelItemState_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::DeleteSelItem_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::GetGameOptions_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::AddScene_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::ModifyScene_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::SetMicropVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::GetMicropVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::SetDesktopVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::GetDesktopVolume_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::GetVideoDevices_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::GetAudioDevices_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::GetSelSceneClass_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}

void CEVDemoCallBack::GetSelSceneInfo_CallBack(IN const bool& bSuccessed, IN const char* strErrInfo)
{
	// ������;
	if (!bSuccessed)
	{
		::MessageBoxA(NULL, strErrInfo, NULL, NULL);
	}
}