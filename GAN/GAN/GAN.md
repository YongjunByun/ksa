# PCA 얼굴 인식 ROC Curve 그리기
###### <strong> 얼굴인식 PCA ROC_Curve

* 언어 : Python
* 프로그램 : jupyter notebook
* 소스코드 : ROC_Curve.ipynb
* 사용한 모듈 : matplotlib, numpy, math, cv2, os, pandas, PIL
* 주요 함수 :

```

 os.lisdir(path) : 경로내 모든 파일 리스트  cv2.cvtColor(image, cv2.COLOR_BGR2GRAY) : 이미지 흑백화  np.reshape(array, shape) : numpy 형태 재배열  list.append(item) : 리스트요소추가  np.zeros_like(array) : array와 같은 형태의 0행렬 생성
 cv2.equalizeHist(image) : 히스토그램 평활화  np.delete(array, index, axis) : array 요소 제거  np.argsort(array) : 정렬시 인덱스 반환  @ : 행렬곱  array.T : 전치행렬  numpy.linalg.norm(array) : 벡터 길이 리턴
 np.dot(array,array) : 행렬곱  plt.hist(array) : 히스토그램 그리기  
 
 ```
 

----------------------------------------

## 데이터

* 데이터 정보
  * 3인 얼굴 이미지 각 50장
  * 150x150으로 read
  * 이미지 흑백화

<img src = "https://user-images.githubusercontent.com/72690336/120681122-045a3c00-c4d6-11eb-9516-82c21932717a.png" width="50%" height="50%">

* PCA
  * 다차원 특징의 벡터로 이루어진 고차원의 정보를 유지하며 저차원으로 축소하여 다변량 데이터를 처리하는 방법
  * 차원에 상관없는 변량의 집합으로 기준 축을 변환하여 특징 벡터를 재배치
  * 영상인식, 주성분 찾기, 데이터 압축 등에 활용

<img src = "https://user-images.githubusercontent.com/72690336/120681506-67e46980-c4d6-11eb-811c-e48a328d333a.png" width="70%" height="70%">


----------------------------------------

## 이미지별 코사인유사도 히스토그램

* 히스토그램
 
<img src = "https://user-images.githubusercontent.com/72690336/120682052-fa850880-c4d6-11eb-9268-59e6b7370a35.png" width="80%" height="80%">
 
-코사인유사도 : 두 벡터가 얼마나 유사한지를 나타내는 정량적인 값, -1~1 사이
-Authentic : 동일인물의 사진을 비교한 코사인유사도
-Imposter : 다른인물의 사진을 비교한 코사인유사도

---------------------------------------------
 
## ROC Curve

* ROC_Curve 그래프

<img src = "https://user-images.githubusercontent.com/72690336/120682643-a62e5880-c4d7-11eb-96e5-59b6fb654b53.png" width="50%" height="50%">
 
-threshold 값을 -1에서 0.05씩 증가시키며 ERR의 값을 기준으로 최적의 threshold 값 탐색
-FAR 부정허용률 : 인식되지 말아야 할 다른 사람을 맞다고 인식한 비율
-FRR 부정거부율 : 인식되어야 할 사람이 인식되지 않는 비율
-ERR : FAR과 FRR이 만나는 지점으로 효율성 및 생체 인증의 척도이다.

* 최적의 파라미터 탐색
 
<img src = "https://user-images.githubusercontent.com/72690336/120682937-fe655a80-c4d7-11eb-90a9-a387858b7c74.png" width="50%" height="50%">

 -Eigen Vector를 25개로 축소시긴 이미지데이터
 -Threshold : 0.2
 -ERR : 0.059


---------------------------------------------


### 개선할 점

* 샤프닝, 블러링, 감마보정 등 여러가지 영상처리 기법을 적용 후 성능이 더 좋아지는지 확인
