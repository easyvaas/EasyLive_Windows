#pragma once
#include "TString\TString.h"
#include <lmcons.h>
#include <map>

typedef std::map<TString, TString> MapPara;

class CUrlString
{
public:
	CUrlString();
	~CUrlString();

	TString GetUrlString();

	void SetUrl(IN TString strUrl);

	void AddPara(IN TString strKey, IN int iValue);
	// ���ͳһ�ߴ˽ӿ���װ;
	void AddPara(IN TString strKey, IN TString strValue);

private:
	TString			m_strUrl;
	//int			m_iParaCount;
	MapPara			m_mapParas;
};