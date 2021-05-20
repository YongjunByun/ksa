
// image_processingDoc.h: CimageprocessingDoc 클래스의 인터페이스
//


#pragma once


class CimageprocessingDoc : public CDocument
{
protected: // serialization에서만 만들어집니다.
	CimageprocessingDoc() noexcept;
	DECLARE_DYNCREATE(CimageprocessingDoc)

// 특성입니다.
public:

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// 구현입니다.
public:
	virtual ~CimageprocessingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// 검색 처리기에 대한 검색 콘텐츠를 설정하는 도우미 함수
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	unsigned char* m_InputImage;
	int m_width;
	int m_height;
	int m_size;
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	unsigned char* m_OutputImage;
	int m_Re_width, m_Re_height, m_Re_size;
	double m_HIST[256];
	double m_Sum_Of_HIST[256];
	unsigned char m_Scale_HIST[256];
	void OnHistoEqual();
	void OnHistoSpec();
	afx_msg void OnDownSampling();
	afx_msg void OnUpSampling();
	afx_msg void OnQuantization();
	afx_msg void OnSumConstant();
	afx_msg void OnSubConstant();
	afx_msg void OnMulConstant();
	afx_msg void OnDivConstant();
	afx_msg void OnAndOperate();
	afx_msg void OnOrOperate();
	afx_msg void OnXorOperate();
	afx_msg void OnNegaTransform();
	afx_msg void OnGammaCorrection();
	afx_msg void OnBinarization();
	afx_msg void OnStressTransform();
	afx_msg void OnHistoStretch();
	afx_msg void OnEndInSearch();
	afx_msg void OnHistogram();
	afx_msg void OnEmbossing();
	afx_msg double** OnMaskProcess(unsigned char* Target, double Mask[3][3]);
	afx_msg double** OnScale(double** Target, int height, int width);
	afx_msg double** Image2DMem(int height, int width);
	double** m_tempImage;
	void OnBlurr();
	void OnGaussianFilter();
	void OnSharpening();
	void OnHpfSharp();
	void OnLpfSharp();
	void OnDiffOperatorHor();
	void OnHomogenOperator();
	double DoubleABS(double X);
	void OnLaplacian();
	void OnNearest();
	void OnBilinear();
	void OnMedianSub();
	void OnBubbleSort(double* A, int MAX);
	void OnSwap(double* a, double* b);
	void OnMeanSub();
	void OnTranslation();
	void OnMirrorHor();
	void OnMirrorVer();
	void OnRotation();
};
