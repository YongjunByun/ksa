
// image_processingView.h: CimageprocessingView 클래스의 인터페이스
//

#pragma once


class CimageprocessingView : public CView
{
protected: // serialization에서만 만들어집니다.
	CimageprocessingView() noexcept;
	DECLARE_DYNCREATE(CimageprocessingView)

// 특성입니다.
public:
	CimageprocessingDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	BITMAPINFO* BmInfo;	//비트맵 영상헤드 선언
	virtual ~CimageprocessingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDownSampling();
	afx_msg void OnUpSampling();
	afx_msg void OnQuantization();
	afx_msg void OnSumConstant();
	afx_msg void OnSubConstant();
	afx_msg void OnMulConstant();
	afx_msg void OnDivConstant();
	void OnAndOperate();
	void OnOrOperate();
	void OnXorOperate();
	void OnNegaTransform();
	afx_msg void OnGammaCorrection();
	afx_msg void OnBinarization();
	afx_msg void OnStressTransform();
	afx_msg void OnHistoStretch();
	afx_msg void OnEndInSearch();
	afx_msg void OnHistogram();
	afx_msg void OnHistoEqual();
	afx_msg void OnHistoSpec();
	afx_msg void OnEmbossing();
	afx_msg void OnBlurr();
	afx_msg void OnGaussianFilter();
	afx_msg void OnSharpning();
	afx_msg void OnHdfSharp();
	afx_msg void OnLpfSharp();
	afx_msg void OnDiffOperatorHor();
	afx_msg void OnHomogenOperator();
	afx_msg void OnLaplacian();
	afx_msg void OnNearest();
	afx_msg void OnBilinear();
	afx_msg void OnMeanSub();
	afx_msg void OnMedianSub();
};

#ifndef _DEBUG  // image_processingView.cpp의 디버그 버전
inline CimageprocessingDoc* CimageprocessingView::GetDocument() const
   { return reinterpret_cast<CimageprocessingDoc*>(m_pDocument); }
#endif

