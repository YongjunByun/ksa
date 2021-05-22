# 혁신성장청년인재 6주 4일차 - CNN 모델 향상시키기
###### <strong> 파이참을 이용한 CNN 구현 - CIFAR-10 이미지 분류

* 언어 : Python
* 프로그램 : Pycharm, Anaconda3
* 소스코드 : cifar10.py - 함수형 코딩
* 사용한 모듈 : tensorflow==2.1.0, keras==2.2.4, matplotlib, numpy, os
* 주요 함수 :

```

 cifar10.load_data() : cifar10 데이터 로드    to_categorical(data, class) : 원핫인코딩    Input(Shape, name)  : 모델 생성 함수 API    Sequential() : 순차 모델 생성   
 Dense(units, activation, name) : 신경망 레이어 추가   Model(Input, Output).compile(loss, optimizer, metrics) : 신경망 모델 인스턴스 생성 
 Conv2D(filters, kernel_size, padding, name) : 합성곱 레이어 추가  MaxPooling2D(pool_size, name) : maxpooling 레이어 추가  Flatten() : 1차원 벡터화
 Dropout() : 드랍아웃  Batchnormalization() : 배치정규화  Activation() : 활성화함수 적용  Adam(lr) : 최적화 함수 아담
 ImageDataGenerator(rotation_range, width_shift_range, height_shift_range, horizontal_flip) : Data Augumentation를 위한 데이터 뻥튀기
 model.fit(data, label, batch_size, epochs, verbose, validation_split) : 학습  model.evaluate(data, label, batch_size) : 모델 예측 성능 평가
 
 ```
 

----------------------------------------

### CIFAR-10

* 데이터 정보

<img src = "https://user-images.githubusercontent.com/72690336/118838419-a0921980-b900-11eb-90db-477e7614cfcd.png" width="50%" height="50%">

-train 셋 50000장, test셋 10000장
-label : 0~9 ['airplane', 'automobile', 'bird', 'cat', 'deer', 'dog', 'frog', 'horse', 'ship', 'truck']

* 오늘의 모델 구조
  * 입력레이어 1, 합성곱 레이어 13, Flatten 1, 은닉레이어 1, 출력레이어 1
  * train : 50000, test : 10000
  * 활성화함수 : WeakyReLU, 출력층 활성화함수 : softmax
  * VGG 구조를 참고하여 합성곱 레이어 필터는 3x3, 각 레이어의 필터 수가 늘어날때마다 Maxpooling 적용
  * stride를 사용하지 않고 오직 Maxpooling으로만 차원을 축소시켜 깊이에 따른 성능 측정
  * 활성화 함수 적용전 배치정규화 적용
  * Dropout은 합성곱레이어에는 적용하지 않고 은닉레이어에만 적용
  * 
----------------------------------------
### CNN - epochs=50

* 데이터 : 위와 동일

* 모델 성능
  * 훈련셋 : loss: 0.1177 - accuracy: 0.9587
  * 테스트셋 : val_loss: 0.5049 - val_accuracy: 0.8748

-지난 일반 실습 모델보다 약 20% 가까이 accuracy가 상승했다.
-훈련셋과 테스트셋간의 loss와 accuracy가 꽤 차이가 나는 것으로 보아 overfitting 문제가 다소 발생하였음을 알 수 있다.

* 학습 모델 그래프

<img src = "https://user-images.githubusercontent.com/72690336/119227164-96ae2780-bb47-11eb-9e82-f3c93b897043.png" width="40%" height="40%">  <img src = "https://user-images.githubusercontent.com/72690336/119227350-5e5b1900-bb48-11eb-9bb1-cffb345883ac.png" width="40%" height="40%">

-epochs 반복 차수가 일정회자부터 상승형태를 보이지 않음. -> 더이상 반복의 의미가 없음 성능향상을 위해서는 모델의 구조를 바꿔야 함.

* 예측 샘플

<img src = "https://user-images.githubusercontent.com/72690336/119227453-e6d9b980-bb48-11eb-9520-a7deb35d9de7.png" width="60%" height="60%">


---------------------------------------------


### 개선할 점

* epochs가 증가할수록 성능의 향상이 있지만 일정 수준 이상부터는 거의 향상이 없음을 확인 
-> 위 모델에서는 epochs를 늘리기 보다는 모델의 파라미터와 구조를 바꾸는 것이 더 효율적일 것으로 판단
