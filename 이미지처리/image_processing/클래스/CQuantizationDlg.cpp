// CQuantizationDlg.cpp: 구현 파일
//

#include "pch.h"
#include "image_processing.h"
#include "CQuantizationDlg.h"
#include "afxdialogex.h"


// CQuantizationDlg 대화 상자

IMPLEMENT_DYNAMIC(CQuantizationDlg, CDialog)

CQuantizationDlg::CQuantizationDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_DIALOG3, pParent)
	, m_QuantBit(0)
{

}

CQuantizationDlg::~CQuantizationDlg()
{
}

void CQuantizationDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_QuantBit);
	DDV_MinMaxInt(pDX, m_QuantBit, 1, 8);
}


BEGIN_MESSAGE_MAP(CQuantizationDlg, CDialog)
//	ON_COMMAND(ID_QUANTIZATION, &CQuantizationDlg::OnQuantization)
END_MESSAGE_MAP()

//CQuantization 메세지 처리기
