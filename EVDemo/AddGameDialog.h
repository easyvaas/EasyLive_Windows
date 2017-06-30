#pragma once

// ��ϷԴ;
class CAddGameDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CAddGameDialog)

public:
	CAddGameDialog(SceneStatus status = SCENE_ADD, CWnd* pParent = NULL);
	virtual ~CAddGameDialog();

	// �Ի�������;
	enum { IDD = IDD_ADDGAMEDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	virtual BOOL OnInitDialog();

	DECLARE_MESSAGE_MAP()

public:
	afx_msg void OnBnClickedGameUpdateButton();
	virtual void OnOK();
	virtual void OnCancel();

protected:
	void AddGameOpts();
	void RemoveAllGameOpts();
	void InitData();

private:
	CComboBox		m_cmbGameOpts;
	SceneStatus		m_staScene;

	// ��Ϸѡ��;
	GameInfo*		m_pGameOpts;
	int				m_iOptsCount;
};
