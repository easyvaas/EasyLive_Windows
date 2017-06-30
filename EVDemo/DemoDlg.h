#pragma once
#include "afxcmn.h"
#include "MessageDlg.h"
#include "CmdInfo.h"
#include "afxwin.h"
#include "ChatUserDlg.h"

// CDemoDlg �Ի���
class CDemoDlg : public CDialogEx
{
// ����
public:
	CDemoDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DEMO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
    afx_msg void OnBnClickedGameButton();
    afx_msg void OnBnClickedScreenshotButton();
    afx_msg void OnBnClickedCameraButton();
    afx_msg void OnBnClickedTextButton();
    afx_msg void OnBnClickedImageButton();
    afx_msg void OnBnClickedStartliveButton();
    afx_msg void OnBnClickedEndliveButton();
	afx_msg void OnBnClickedSceneMoveupButton();
	afx_msg void OnBnClickedSceneMovedowmButton();
	afx_msg void OnBnClickedSceneMovetopButton();
	afx_msg void OnBnClickedSceneMovebottomButton();
	afx_msg void OnBnClickedSceneFullButton();
	afx_msg void OnBnClickedSceneSetButton();
	afx_msg void OnBnClickedSceneDeleteButton();

	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);

	virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);

	static void GetLID_CallBack(CmdInfo& cmdInfo);

	LRESULT VedioOnButtonUp(UINT uMessage, WPARAM wParam, LPARAM lParam);

private:
	CSliderCtrl		m_ctrMicrop;
	CSliderCtrl		m_ctrDestop;

	CMessageDlg		m_dlgMessage;
	CChatUserDlg	m_dlgChatUser;
public:
	CEdit m_edtPushUrl;
	afx_msg void OnBnClickedSetButton();
	afx_msg void OnBnClickedWindowsButton();
	afx_msg void OnBnClickedWhiteButton();
};
