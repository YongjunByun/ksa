// CDownSampleDlg.cpp: 구현 파일
//


#include "pch.h"
#include "afxdialogex.h"
#include "image_processing.h"
#include "image_processingDoc.h"
#include "CDownSampleDlg.h" 


// CDownSampleDlg 대화 상자

IMPLEMENT_DYNAMIC(CDownSampleDlg, CDialog)

CDownSampleDlg::CDownSampleDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG1, pParent)
	, n_DownSampleRate(0)
{

}

CDownSampleDlg::~CDownSampleDlg() {

}

void CDownSampleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, n_DownSampleRate);
	DDV_MinMaxInt(pDX, n_DownSampleRate, 1, 32);
}


BEGIN_MESSAGE_MAP(CDownSampleDlg, CDialog)
END_MESSAGE_MAP()


// CDownSampleDlg 메시지 처리기
