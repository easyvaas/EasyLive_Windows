#include "stdafx.h"
#include "resource.h"
#include "WndSelDlg.h"
#include "afxdialogex.h"
#include <algorithm>

IMPLEMENT_DYNAMIC(CWndSelDlg, CDialog)

CWndSelDlg::CWndSelDlg(CImage &image, CWnd* pParent /*=NULL*/)
: CDialog(CWndSelDlg::IDD, pParent), m_Image(image)
{
	m_bButtonDown = FALSE;
	m_bDownMove = FALSE;
	m_rcSel = CRect(0, 0, 0, 0);
	m_ptButtonDown = CPoint(0, 0);
}

CWndSelDlg::~CWndSelDlg()
{
}

void CWndSelDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWndSelDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

void CWndSelDlg::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// ��������˫�����ͼ����ʱImage;
	if (m_tmpImage.IsNull())
	{
		m_tmpImage.Create(m_Image.GetWidth(), m_Image.GetHeight(), 24);
	}

	// ����ʱImage�ϻ�������ͼ��;
	HDC hDC = m_tmpImage.GetDC();
	CDC *pDC = CDC::FromHandle(hDC);
	m_Image.Draw(hDC, 0, 0);

	// ������ͼ��ȫ�����;
	byte *pData = (byte *)m_tmpImage.GetBits();
	for (int i = 0; i < m_tmpImage.GetHeight(); i++)
	{
		byte *pLine = pData;
		for (int j = 0; j < m_tmpImage.GetWidth(); j++)
		{
			pLine[j * 3 + 0] /= 2;
			pLine[j * 3 + 1] /= 2;
			pLine[j * 3 + 2] /= 2;
		}
		pData += m_tmpImage.GetPitch();
	}

	// ��ѡ�е��������Ϊ��ɫ;
	CRect rc = m_rcSel;
	pDC->FillSolidRect(rc, RGB(251, 102, 85));

	// ѡ�������ڲ�������ͼ��ʵ�ֱ߿����Ч��;
	if (rc.Width() > 10 && rc.Height() > 10)
	{
		rc.DeflateRect(5, 5, 5, 5);
		m_Image.Draw(hDC, rc.left, rc.top, rc.Width(), rc.Height(), rc.left, rc.top, rc.Width(), rc.Height());
	}

	// �����������λ�û����ݺ�������;
	CPoint   point;
	GetCursorPos(&point);
	ScreenToClient(&point);
	CPen pen;
	pen.CreatePen(PS_SOLID, 1, RGB(251, 102, 85));
	pDC->SelectObject(&pen);
	pDC->MoveTo(point.x, 0);
	pDC->LineTo(point.x, m_Image.GetHeight());
	pDC->MoveTo(0, point.y);
	pDC->LineTo(m_Image.GetWidth(), point.y);

	// ������ʾ����;
	CFont font;
	font.CreatePointFont(80, _T("Arial"));
	pDC->SelectObject(&font);
	point.Offset(2, 2);
	pDC->SetBkMode(TRANSPARENT);
	pDC->SetTextColor(RGB(0, 150, 0));
	pDC->SetTextAlign(DT_TOP | DT_LEFT);
	CString strText = _T("��������ѡ��������ڴ��ڣ�Esc�˳���");
	pDC->TextOut(point.x, point.y, strText);
	m_tmpImage.ReleaseDC();

	// ����ʱ���ƵĶ�����䵽ʵ����ʾ����;
	m_tmpImage.Draw(dc.GetSafeHdc(), 0, 0);
}

BOOL CWndSelDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	// ��ȡ���еĿɼ�����;
	EnumWindows(EnumProc, (LPARAM)&m_vecWnd);
	// ���մ��������С��������;
	std::sort(m_vecWnd.begin(), m_vecWnd.end());
	ShowWindow(SW_MAXIMIZE);

	return TRUE;
}

void CWndSelDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_bButtonDown = TRUE;
	m_ptButtonDown = point;

	CDialog::OnLButtonDown(nFlags, point);
}

void CWndSelDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	CDialog::OnLButtonUp(nFlags, point);
	OnOK();
}

void CWndSelDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	CDialog::OnMouseMove(nFlags, point);

	// ���û�б�����ʱ����������ڵ�λ�õĴ���������Ϊѡ������;
	if (m_bButtonDown)
	{
		m_bDownMove = TRUE;
		m_rcSel = CRect(m_ptButtonDown, point);
		if (m_rcSel.left > m_rcSel.right)
		{
			std::swap(m_rcSel.left, m_rcSel.right);
		}
		if (m_rcSel.top > m_rcSel.bottom)
		{
			std::swap(m_rcSel.top, m_rcSel.bottom);
		}
	}
	else
	{
		for (size_t i = 0; i < m_vecWnd.size(); i++)
		{
			if (m_vecWnd[i].rc.PtInRect(point))
			{
				m_rcSel = m_vecWnd[i].rc;
				break;
			}
		}
	}
	Invalidate(FALSE);
}

CRect CWndSelDlg::GetSelRect()
{
	return m_rcSel;
}

BOOL CWndSelDlg::EnumProc(HWND hWnd, LPARAM lPara)
{
	// ���ɼ��Ĵ��ھͲ��ض��һ����;
	if (!::IsWindowVisible(hWnd))
	{
		return TRUE;
	}

	// ���˳ߴ粻���ʵĴ���;
	WndNode node;
	node.hWnd = hWnd;
	::GetWindowRect(hWnd, node.rc);
	if (node.rc.Width() == 0 || node.rc.Height() == 0)
	{
		return TRUE;
	}

	//���ô��ڼ����б�;
	WndNodeVec* pWndVec = reinterpret_cast<WndNodeVec*>(lPara);
	ASSERT(pWndVec);
	pWndVec->push_back(node);
	return TRUE;
}