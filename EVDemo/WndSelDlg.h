#pragma once
#include <vector>

// ��������;
class CWndSelDlg : public CDialog
{
	DECLARE_DYNAMIC(CWndSelDlg)

public:
	CWndSelDlg(CImage &image, CWnd* pParent = NULL);
	virtual ~CWndSelDlg();

	enum { IDD = IDD_SEL_WND };

	// ��ȡ��ǰѡ�������;
	CRect GetSelRect();

protected:
	virtual void DoDataExchange(CDataExchange* pDX);

	DECLARE_MESSAGE_MAP()
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);

	// ����ö�����д��ڵĴ��ڹ���;
	static BOOL CALLBACK EnumProc(HWND hWnd, LPARAM lp);

	// ������Ϣ�ڵ�;
	struct WndNode
	{
		HWND hWnd;
		CRect rc;

		// ����ר��;
		bool operator < (const WndNode &node)
		{
			return rc.Width() * rc.Height() < node.rc.Width() * node.rc.Height();
		}
	};
	typedef std::vector<WndNode> WndNodeVec;

	// ��ǰ���еĿɼ�����;
	WndNodeVec m_vecWnd;
	// �ϲ㴰��������������;
	CImage &m_Image;
	// �û�˫�����ͼ����ʱ����;
	CImage m_tmpImage;
	// �û���ǰѡ�е�����;
	CRect m_rcSel;
	// ��ʶ��굱ǰ�Ƿ���;
	bool m_bButtonDown;
	// ��ʶ����Ƿ��ڰ���״̬���ƶ���;
	bool m_bDownMove;
	// ��ǰ��걻���µ�λ��;
	CPoint m_ptButtonDown;
};
