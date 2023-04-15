// DlgImage.cpp: 구현 파일
//

#include "pch.h"
#include "iGlim_Report.h"
#include "afxdialogex.h"
#include "DlgImage.h"

#define COLOR_RED RGB(0xff, 0, 0)
#define COLOR_GREEN RGB(0, 0xff, 0)
#define COLOR_BLUE RGB(0, 0, 0xff)
#define COLOR_YELLOW RGB(0xff, 0xff, 0)

// CDlgImage 대화 상자

IMPLEMENT_DYNAMIC(CDlgImage, CDialogEx)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DlgImage, pParent)
{
	m_pParent = pParent;
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgImage::OnBnClickedButton1)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage 메시지 처리기

#include "iGlim_ReportDlg.h"
void CDlgImage::OnBnClickedButton1()
{
	static int n = 100;
	CiGlimReportDlg* pDlg = (CiGlimReportDlg*)m_pParent;
	pDlg->callFunc(n++);
}


BOOL CDlgImage::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	//AfxMessageBox(_T("TEST"));
	MoveWindow(0, 0, 640, 480);
	InitImage();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}

void CDlgImage::InitImage() {

	int nWidth = 640;
	int nHeight = 480;
	/*int nWidth = 4096*5;
	int nHeight = 4096*5;*/
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++) {
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
			m_image.SetColorTable(0, 256, rgb);
		}
	}

	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);


}

void CDlgImage::OnPaint()
{
	CPaintDC dc(this);

	if (m_image) {
		m_image.Draw(dc, 0, 0);
	}

	drawData(&dc);

}


void CDlgImage::drawData(CDC* pDC) {

	CRect rect;
	CPen pen;
	pen.CreatePen(PS_SOLID, 5, COLOR_YELLOW);
	CPen* pOldPen = pDC->SelectObject(&pen);
	//pDC->Ellipse(rect);
	for (int i = 0; i < m_nDataCount; i++) {
		rect.SetRect(m_ptData[i], m_ptData[i]);
		rect.InflateRect(50, 50);
		pDC->Ellipse(rect);
	}
	pDC->SelectObject(pOldPen);
}