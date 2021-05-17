# 혁신성장청년인재 6주 1일차 - DNN, CNN
###### <strong> 파이참을 이용한 DNN, CNN 구현 - MNIST 손글씨 분류

* 언어 : Python
* 프로그램 : Pycharm, Anaconda3
* 소스코드 : mnist.py(DNN), mnist_CNN.py - 함수형 코딩
* 사용한 모듈 : tensorflow==2.1.0, keras==2.2.4, matplotlib, numpy
* 주요 함수 :

```

 mnist.load_data() : mnist 데이터 로드    to_categorical(data, class) : 원핫인코딩    Input(Shape, name)  : 모델 생성 함수 API    Sequential() : 순차 모델 생성   
 Dense(units, activation, name) : 신경망 레이어 추가   Model(Input, Output).compile(loss, optimizer, metrics) : 신경망 모델 인스턴스 생성 
 Conv2D(filters, kernel_size, padding, name) : 합성곱 레이어 추가  MaxPooling2D(pool_size, name) : maxpooling 레이어 추가  Flatten() : 1차원 벡터화
 model.fit(data, label, batch_size, epochs, verbose, validation_split) : 학습  model.evaluate(data, label, batch_size) : 모델 예측 성능 평가
 
 ```
 

----------------------------------------

### 환경 준비

* 아나콘다 가상환경 생성(ksa_deeplearning)

<img src = "https://user-images.githubusercontent.com/72690336/118500260-9c2ffa00-b762-11eb-9e22-213cdc5c6cb2.png" width="50%" height="50%">

* 파이참 설치 및 가상환경 연결

[File] -> [Settings] -> [Project: pycharm] -> [Python Interpreter] -> [아나콘다 가상환경 경로의 python.exe 더블클릭]

<img src = "https://user-images.githubusercontent.com/72690336/118503181-57f22900-b765-11eb-9df7-ede0ae64c3a1.png" width="50%" height="50%">

-해당 가상환경의 패키지들이 load된 것을 볼 수 있다.

----------------------------------------

### DNN

* 이미지 샘플

<img src = "https://user-images.githubusercontent.com/72690336/118503878-fa121100-b765-11eb-864d-434c320803d5.png" width="50%" height="50%">

-train 셋 60000장, test셋 10000장

* 모델 구조
  * 입력레이어 1, 히든레이어 4, 출력레이어 1
  * train : 48000, validation : 12000
  * 활성화함수 : relu, 출력층 활성화함수 : softmax

<img src = "https://user-images.githubusercontent.com/72690336/118507750-7bb76e00-b769-11eb-9dd7-8598563529be.png" width="50%" height="50%">

<img src = "https://user-images.githubusercontent.com/72690336/118504411-73116880-b766-11eb-86e7-1223b22e6b00.png" width="50%" height="50%">

* 모델 성능
  * 훈련셋 : loss: 0.0187 - accuracy: 0.9940 - val_loss: 0.1067 - val_accuracy: 0.9753
  * 테스트셋 : loss: 0.0974 - accuracy: 0.9758

* 학습 모델 그래프

<img src = "https://user-images.githubusercontent.com/72690336/118505567-7e18c880-b767-11eb-8e9a-fc26a7f1de2c.png" width="40%" height="40%">  <img src = "https://user-images.githubusercontent.com/72690336/118506467-4c543180-b768-11eb-968a-9697f8b80e38.png" width="40%" height="40%">

-epochs 반복 차수가 높아질수록 점점 모델 향상 정도가 낮아진다. 

----------------------------------------

### CNN

* 데이터 : 위와 동일

* 모델 구조
  * 입력레이어 1, 합성곱 레이어(각 층마다 MaxPooling 적용) 2, Flatten 1, 은닉레이어 1, 출력레이어 1
  * train : 48000, validation : 12000
  * Padding : 사용안함, 활성화함수 : relu, 출력층 활성화함수 : softmax

<img src = "https://user-images.githubusercontent.com/72690336/118510261-c0440900-b76b-11eb-8131-757ec8aa496d.png" width="70%" height="70%">

* 모델 성능
  * 훈련셋 : loss: 0.0052 - accuracy: 0.9981 - val_loss: 0.0567 - val_accuracy: 0.9872
  * 테스트셋 : loss: 0.0468 - accuracy: 0.9886

-DNN보다 train과 validation셋에 대한 성능이 소폭 상승했다.
-test셋에 대한 accuracy 또한 상승했다. -> DNN보다 이미지 분류에 더 효율적인 예측 결과를 보인다.

* 학습 모델 그래프

<img src = "https://user-images.githubusercontent.com/72690336/118532726-3eaba580-b782-11eb-87fa-4f00966808b2.png" width="40%" height="40%">  <img src = "https://user-images.githubusercontent.com/72690336/118532793-4f5c1b80-b782-11eb-99cf-7734501a867e.png" width="40%" height="40%">

-epochs 반복 차수가 높아질수록 점점 모델 향상 정도가 낮아진다. 
-1회 이상 반복 수행 시점부터 train과 validation 셋의 성능이 차이가 나기 시작한다.

----------------------------------------

### 의문점

* CNN에서 은닉층을 더 추가하면 결과가 어떻게 되는가?
* epoch가 1 이상 시점부터 오버피팅이 시작되는 것인가?
