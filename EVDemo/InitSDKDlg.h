#pragma once
#include "Resource.h"

// CInitSDKDlg �Ի���

class CInitSDKDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInitSDKDlg)

public:
	CInitSDKDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CInitSDKDlg();

	// �Ի�������
	enum { IDD = IDD_INITSDK_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedInitBtn();
	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
};