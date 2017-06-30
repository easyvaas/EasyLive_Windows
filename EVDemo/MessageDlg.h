#pragma once
#include "afxwin.h"

// CMessageDlg �Ի���

class CMessageDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMessageDlg)

public:
	CMessageDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMessageDlg();

// �Ի�������
	enum { IDD = IDD_MESSAGE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    CEdit m_msgShowEdit;
    afx_msg void OnBnClickedButtonSend();
    afx_msg void OnBnClickedButtonClear();
    CEdit m_editInput;
    virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnClose();
    afx_msg void OnBnClickedButtonJointopic();
    afx_msg void OnBnClickedButtonLeavetopic();
    afx_msg void OnBnClickedButtonDisconnect();
    afx_msg void OnBnClickedButtonConnect();
    afx_msg void OnBnClickedButtonLike();
    CEdit m_editTopicName;
    CString m_strTopicName;
    CEdit m_editSenderName;
    CEdit m_editUserId;
};
