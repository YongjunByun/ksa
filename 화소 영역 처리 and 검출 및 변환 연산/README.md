# 혁신성장청년인재 5주 4일차 - 화소 영역 처리
###### <strong> 엠보싱, 블러링, 가우시안 필터, 샤프닝, 고주파 필터 샤프닝, 저주파 필터 샤프닝, 에지 검출(이동과 차분, 유사 연산자 기법, 라플라시안)

* 언어 : C++
* 프로그램 : Visual Studio 2019 WFC Visual C++ 솔루션
* 추가된 클래스(원본은 image_processing 폴더 참조) : image_processingDoc.cpp, image_processingView.cpp
* 함수 : 

```

 OnEmbossing() : 엠보싱처리    OnBlurr() : 블러링 처리    OnGausianFilter() : 가우시안 필터 처리    OnSharpening() : 샤프닝 처리   OnHpfSharp() : 고주파 필터 샤프닝
 OnLpfSharp() : 저주파 필터 샤프닝    OnDiffOperatorHor() : 이동과 차분(수평처리)    OnHomogenOperator() : 유사 연산자 기법   OnLaplacian() : 라플라시안
 
 ```
 
</strong>

----------------------------------------

### 엠보싱 처리

* 마스크 선택에 따른 변화

![image](https://user-images.githubusercontent.com/72690336/118119977-265a2480-b42a-11eb-8970-739c8df7acdf.png) ![image](https://user-images.githubusercontent.com/72690336/118120209-7afd9f80-b42a-11eb-8838-a4013eb6191f.png)

