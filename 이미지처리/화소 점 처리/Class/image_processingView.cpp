
// image_processingView.cpp: CimageprocessingView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "image_processing.h"
#endif

#include "image_processingDoc.h"
#include "image_processingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CimageprocessingView

IMPLEMENT_DYNCREATE(CimageprocessingView, CView)

BEGIN_MESSAGE_MAP(CimageprocessingView, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_COMMAND(ID_DOWN_SAMPLING, &CimageprocessingView::OnDownSampling)
	ON_COMMAND(ID_UP_SAMPLING, &CimageprocessingView::OnUpSampling)
	ON_COMMAND(ID_QUANTIZATION, &CimageprocessingView::OnQuantization)
	ON_COMMAND(ID_SUM_CONSTANT, &CimageprocessingView::OnSumConstant)
	ON_COMMAND(ID_SUB_CONSTANT, &CimageprocessingView::OnSubConstant)
	ON_COMMAND(ID_MUL_CONSTANT, &CimageprocessingView::OnMulConstant)
	ON_COMMAND(ID_DIV_CONSTANT, &CimageprocessingView::OnDivConstant)
	ON_COMMAND(ID_AND_OPERATE, &CimageprocessingView::OnAndOperate)
	ON_COMMAND(ID_OR_OPERATE, &CimageprocessingView::OnOrOperate)
	ON_COMMAND(ID_XOR_OPERATE, &CimageprocessingView::OnXorOperate)
	ON_COMMAND(ID_NEGA_TRANSFORM, &CimageprocessingView::OnNegaTransform)
	ON_COMMAND(ID_GAMMA_CORRECTION, &CimageprocessingView::OnGammaCorrection)
	ON_COMMAND(ID_BINARIZATION, &CimageprocessingView::OnBinarization)
	ON_COMMAND(ID_STRESS_TRANSFORM, &CimageprocessingView::OnStressTransform)
	ON_COMMAND(ID_HISTO_STRETCH, &CimageprocessingView::OnHistoStretch)
	ON_COMMAND(ID_END_IN_SEARCH, &CimageprocessingView::OnEndInSearch)
	ON_COMMAND(ID_HISTOGRAM, &CimageprocessingView::OnHistogram)
	ON_COMMAND(ID_HISTO_EQUAL, &CimageprocessingView::OnHistoEqual)
	ON_COMMAND(ID_HISTO_SPEC, &CimageprocessingView::OnHistoSpec)
END_MESSAGE_MAP()

// CimageprocessingView 생성/소멸

CimageprocessingView::CimageprocessingView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CimageprocessingView::~CimageprocessingView()
{
}

BOOL CimageprocessingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CimageprocessingView 그리기

void CimageprocessingView::OnDraw(CDC* pDC)
{
	CimageprocessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	int i, j;
	unsigned char R, G, B;
	// 입력 영상 출력
	for (i = 0; i < pDoc->m_height; i++) {
		for (j = 0; j < pDoc->m_width; j++) {
			R = pDoc->m_InputImage[i * pDoc->m_width + j];
			G = B = R;
			pDC->SetPixel(j + 5, i + 5, RGB(R, G, B));
		}
	}

	// 축소된 영상 출력
	for (i = 0; i < pDoc->m_Re_height; i++) {
		for (j = 0; j < pDoc->m_Re_width; j++) {
			R = pDoc->m_OutputImage[i * pDoc->m_Re_width + j];
			G = B = R;
			pDC->SetPixel(j + pDoc->m_width + 10, i + 5, RGB(R, G, B));
		}
	}

}


// CimageprocessingView 인쇄

BOOL CimageprocessingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CimageprocessingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CimageprocessingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CimageprocessingView 진단

#ifdef _DEBUG
void CimageprocessingView::AssertValid() const
{
	CView::AssertValid();
}

void CimageprocessingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CimageprocessingDoc* CimageprocessingView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CimageprocessingDoc)));
	return (CimageprocessingDoc*)m_pDocument;
}
#endif //_DEBUG


// CimageprocessingView 메시지 처리기


void CimageprocessingView::OnDownSampling()
{
	// TODO: Add your command handler code here
	CimageprocessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnDownSampling(); // Doc 클래스에 OnDownSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신
}



void CimageprocessingView::OnUpSampling()
{
	// TODO: Add your command handler code here
	CimageprocessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnUpSampling(); // Doc 클래스에 OnUpSampling 함수 호출

	Invalidate(TRUE); // 화면 갱신

}


void CimageprocessingView::OnQuantization()
{
	CimageprocessingDoc* pDoc = GetDocument(); // Doc 클래스 참조
	ASSERT_VALID(pDoc);

	pDoc->OnQuantization(); // Doc 클래스에 OnQuantization 함수 호출

	Invalidate(TRUE); // 화면 갱신

}


void CimageprocessingView::OnSumConstant()
{
	CimageprocessingDoc* pDoc = GetDocument();
	// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSumConstant();

	Invalidate(TRUE);

}


void CimageprocessingView::OnSubConstant()
{
	CimageprocessingDoc* pDoc = GetDocument();// 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnSubConstant();

	Invalidate(TRUE);

}


void CimageprocessingView::OnMulConstant()
{
	CimageprocessingDoc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnMulConstant();

	Invalidate(TRUE);

}


void CimageprocessingView::OnDivConstant()
{
	CimageprocessingDoc* pDoc = GetDocument(); // 도큐먼트 클래스 참조
	ASSERT_VALID(pDoc); // 인스턴스 주소를 가져옴

	pDoc->OnDivConstant();

	Invalidate(TRUE);

}


void CimageprocessingView::OnAndOperate()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnAndOperate();

	Invalidate(TRUE);

}


void CimageprocessingView::OnOrOperate()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnOrOperate();

	Invalidate(TRUE);

}


void CimageprocessingView::OnXorOperate()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	pDoc->OnXorOperate();
	Invalidate(TRUE);

}

void CimageprocessingView::OnNegaTransform()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnNegaTransform();

	Invalidate(TRUE);

}


void CimageprocessingView::OnGammaCorrection()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnGammaCorrection();

	Invalidate(TRUE);


}


void CimageprocessingView::OnBinarization()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnBinarization();

	Invalidate(TRUE);

}


void CimageprocessingView::OnStressTransform()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnStressTransform();

	Invalidate(TRUE);

}


void CimageprocessingView::OnHistoStretch()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoStretch();

	Invalidate(TRUE);

}


void CimageprocessingView::OnEndInSearch()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnEndInSearch();

	Invalidate(TRUE);

}


void CimageprocessingView::OnHistogram()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistogram();
	Invalidate(TRUE);

}


void CimageprocessingView::OnHistoEqual()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoEqual();

	Invalidate(TRUE);

}


void CimageprocessingView::OnHistoSpec()
{
	CimageprocessingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	pDoc->OnHistoSpec();

	Invalidate(TRUE);

}
