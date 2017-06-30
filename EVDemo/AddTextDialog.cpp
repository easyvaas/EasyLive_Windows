#include "stdafx.h"
#include "Demo.h"
#include "AddTextDialog.h"

IMPLEMENT_DYNAMIC(CAddTextDialog, CDialogEx)

CAddTextDialog::CAddTextDialog(SceneStatus status /*= SCENE_ADD*/, CWnd* pParent /*=NULL*/)
	: CDialogEx(CAddTextDialog::IDD, pParent)
{
	m_staScene = status;
}

CAddTextDialog::~CAddTextDialog()
{
}

void CAddTextDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEXTFONT_NAME_COMBO, m_cmbFontName);
	DDX_Control(pDX, IDC_TEXTFONT_COLOR_BUTTON, m_btnFontColor);
	DDX_Control(pDX, IDC_TEXTFONT_BOLD_CHECK, m_btnFontBold);
	DDX_Control(pDX, IDC_TEXTFONT_ITALIC_CHECK, m_btnFontItalic);
	DDX_Control(pDX, IDC_TEXTFONT_UNDERLINE_CHECK, m_btnUnderLine);
	DDX_Control(pDX, IDC_TEXT_VER_CHECK, m_btnTextVer);
	DDX_Control(pDX, IDC_TEXT_SPEED_SLIDER, m_ctrSpeed);
	DDX_Control(pDX, IDC_TEXT_OUTLINE_COLOR_CHECK, m_btnOutLineColor);
	DDX_Control(pDX, IDC_TEXT_OUTLINE_THICK_CHECK, m_edtOutLineThick);
	DDX_Control(pDX, IDC_TEXT_OUTLINE_CHECK, m_btnOutLineUsed);
	DDX_Control(pDX, IDC_TEXT_CONTENT_EDIT, m_edtContent);
}

BEGIN_MESSAGE_MAP(CAddTextDialog, CDialogEx)
	ON_BN_CLICKED(IDC_TEXT_OUTLINE_CHECK, &CAddTextDialog::OnBnClickedTextOutlineCheck)
END_MESSAGE_MAP()

BOOL CAddTextDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CStringArray arrName;
	arrName.Add(_T("΢���ź�"));
	arrName.Add(_T("����"));
	arrName.Add(_T("����"));
	arrName.Add(_T("�����п�"));
	for (int i = 0; i < arrName.GetCount(); i++)
	{
		m_cmbFontName.InsertString(i, arrName.GetAt(i));
	}
	m_cmbFontName.SetCurSel(0);

	if (SCENE_MODIFY == m_staScene)
	{
		InitData();
	}

	DisplayOutline();
	return TRUE;
}

void CAddTextDialog::InitData()
{
	SetDlgItemText(IDOK, _T("ȷ��"));

	TextInfo* pScene = new TextInfo();
	AfxGetEVLive()->GetSelSceneInfo(pScene);

	CString strContent = CA2CT(pScene->strContent);
	m_edtContent.SetWindowText(strContent);

	CString strFontName = CA2CT(pScene->strFontName);
	for (int i = 0; i < m_cmbFontName.GetCount(); i++)
	{
		CString strItemText;
		m_cmbFontName.GetLBText(i, strItemText);
		if (0 == strFontName.Compare(strItemText))
		{
			m_cmbFontName.SetCurSel(i);
			break;
		}
	}

	COLORREF dwFontColor = pScene->dwFontColor;
	m_btnFontColor.SetColor(dwFontColor);

	// �Ӵ�;
	int iBold = pScene->iBold;
	m_btnFontBold.SetCheck(iBold);
	// б��;
	int iItalic = pScene->iItalic;
	m_btnFontItalic.SetCheck(iItalic);
	// �»���;
	int iUnderLine = pScene->iUnderLine;
	m_btnUnderLine.SetCheck(iUnderLine);
	// ��ֱ��ʾ;
	int iVer = pScene->iVer;
	m_btnTextVer.SetCheck(iVer);
	// �����ٶ�;
	int iScrollSpeed = pScene->iScrollSpeed;
	m_ctrSpeed.SetPos(iScrollSpeed);

	// �ı���߿�;
	int iOutLineUsed = pScene->iOutLineUsed;
	m_btnOutLineUsed.SetCheck(iOutLineUsed);
	COLORREF dwOutLineColor = pScene->dwOutLineColor;
	m_btnOutLineColor.SetColor(dwOutLineColor);

	CString strOutLineSize;
	strOutLineSize.Format(_T("%d"), pScene->iOutLineSize);
	m_edtOutLineThick.SetWindowText(strOutLineSize);
}

void CAddTextDialog::OnBnClickedTextOutlineCheck()
{
	DisplayOutline();
}

void CAddTextDialog::DisplayOutline()
{
	if (m_btnOutLineUsed.GetCheck())
	{
		m_btnOutLineColor.EnableWindow(TRUE);
		m_edtOutLineThick.EnableWindow(TRUE);
	}
	else
	{
		m_btnOutLineColor.EnableWindow(FALSE);
		m_edtOutLineThick.EnableWindow(FALSE);
	}
}

void CAddTextDialog::OnOK()
{
	TextInfo textInfo;
	CString strContent;
	m_edtContent.GetWindowText(strContent);
	if (strContent.IsEmpty())
	{
		MessageBox(_T("�ı����ݲ���Ϊ�գ�"));
		m_edtContent.SetFocus();
		return;
	}
	if (strContent.GetLength() > 200)
	{
		MessageBox(_T("�ı����ݹ���������200���ڣ�"));
		m_edtContent.SetFocus();
		return;
	}
	strcpy_s(textInfo.strContent, CT2CA(strContent.GetString()));

	// ��������;
	CString strFontName;
	int iSel = m_cmbFontName.GetCurSel();
	m_cmbFontName.GetLBText(iSel, strFontName);
	strcpy_s(textInfo.strFontName, CT2CA(strFontName.GetString()));
	// ��ɫ;
	textInfo.dwFontColor = m_btnFontColor.GetColor();
	// �Ӵ�;
	textInfo.iBold = m_btnFontBold.GetCheck() ? 1 : 0;
	// б��;
	textInfo.iItalic = m_btnFontItalic.GetCheck() ? 1 : 0;
	// �»���;
	textInfo.iUnderLine = m_btnUnderLine.GetCheck() ? 1 : 0;
	// ��ֱ��ʾ;
	textInfo.iVer = m_btnTextVer.GetCheck() ? 1 : 0;
	// �����ٶ�;
	textInfo.iScrollSpeed = m_ctrSpeed.GetPos();

	// �ı���߿�;
	textInfo.iOutLineUsed = m_btnOutLineUsed.GetCheck() ? 1 : 0;
	textInfo.dwOutLineColor = m_btnOutLineColor.GetColor();
	CString strSize;
	m_edtOutLineThick.GetWindowText(strSize);
	textInfo.iOutLineSize = _ttoi(strSize);
	textInfo.iOutlineOpacity = 100; // ͸����;

	switch (m_staScene)
	{
		case SCENE_ADD:
		{
			if (!AfxGetEVLive()->AddScene(&textInfo))
			{
				//MessageBox(EV_GetErrorInfo().c_str());
				return;
			}
		}
		break;
	case SCENE_MODIFY:
		{
			if (!AfxGetEVLive()->ModifyScene(&textInfo))
			{
				//MessageBox(EV_GetErrorInfo().c_str());
				return;
			}
		}
		break;
	default:
		break;
	}

	CDialogEx::OnOK();
}

void CAddTextDialog::OnCancel()
{
	CDialogEx::OnCancel();
}