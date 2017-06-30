#pragma once

// ��ϷԴ;
class CAddWindowDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAddWindowDialog)

public:
	CAddWindowDialog(SceneStatus status = SCENE_ADD, CWnd* pParent = NULL);
	virtual ~CAddWindowDialog();

	// �Ի�������;
	enum { IDD = IDD_ADDWINDOWDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedGameUpdateButton();
	virtual void OnOK();
	virtual void OnCancel();

protected:
	void AddWindowOpts();
	void RemoveAllGameOpts();
	void InitData();

private:
	CComboBox		m_cmbWindowOpts;
	SceneStatus		m_staScene;

	// ��Ϸѡ��;
	GameInfo*		m_pWindowOpts;
	int				m_iOptsCount;
};
