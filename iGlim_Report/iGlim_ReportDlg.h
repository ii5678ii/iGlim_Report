
// iGlim_ReportDlg.h: 헤더 파일
//


#include"DlgImage.h"

#pragma once

// CiGlimReportDlg 대화 상자
class CiGlimReportDlg : public CDialogEx
{
// 생성입니다.
public:
	CiGlimReportDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	CDlgImage* m_pDlgImage;
	CDlgImage* m_pDlgImageResult;
private:
	CImage m_image;
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_IGLIM_REPORT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:


	afx_msg void OnBnClickedButton1();
//	afx_msg void OnDestroy();
	afx_msg void OnDestroy();
	void callFunc(int n);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	void showdisplay();
};
