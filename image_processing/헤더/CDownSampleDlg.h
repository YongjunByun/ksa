#pragma once


// CDownSampleDlg 대화 상자

class CDownSampleDlg : public CDialog
{
	DECLARE_DYNAMIC(CDownSampleDlg)

public:
	CDownSampleDlg(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDownSampleDlg();

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	int n_DownSampleRate;
};
