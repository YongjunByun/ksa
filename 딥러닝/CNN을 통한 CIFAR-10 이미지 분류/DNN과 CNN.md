# 혁신성장청년인재 6주 1일차 - DNN, CNN
###### <strong> 파이참을 이용한 DNN, CNN 구현 - MNIST 손글씨 분류

* 언어 : Python
* 프로그램 : Pycharm, Anaconda3
* 소스코드 : mnist.py(DNN), mnist_CNN.py - 함수형 코딩
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
  * 입력레이어 1, 합성곱 레이어 2, Flatten 1, 은닉레이어 1, 출력레이어 1
  * train : 40000, validation : 10000, test : 10000
  * 활성화함수 : WeakyReLU, 출력층 활성화함수 : softmax
  * Dropout : 주로 활성화함수 적용 후에 적용한 결과가 더 좋은 것으로 확인
  * Batchnormalization : 각 연산층에 전달되기 전에 적용
  * Maxpooling : 활성화함수와 Dropout이 끝난 

<img src = "https://user-images.githubusercontent.com/72690336/118510261-c0440900-b76b-11eb-8131-757ec8aa496d.png" width="70%" height="70%">

----------------------------------------
### DNN

* 데이터 : 위와 동일

* 모델 구조
  * 입력레이어 1, 은닉레이어 4(은닉노드 256개), 출력레이어 1
  * train : 40000, validation : 10000
  * 활성화함수 : relu, 출력층 활성화함수 : softmax

* 모델 성능
  * 훈련셋 : loss: 1.3444 - accuracy: 0.5143 - val_loss: 1.5736 - val_accuracy: 0.4540
  * 테스트셋 : loss: 1.5486 - accuracy: 0.4532

-DNN은 컬러 이미지 분류에 매우 낮은 성능을 보임.
-과적합은 없으나 동전던지기보다 낮은 확률을 보인다.

* 학습 모델 그래프

<img src = "https://user-images.githubusercontent.com/72690336/118842870-835f4a00-b904-11eb-9b4f-cccf92f16163.png" width="40%" height="40%">  <img src = "https://user-images.githubusercontent.com/72690336/118842982-983bdd80-b904-11eb-98ae-6ba5b734c764.png" width="40%" height="40%">

-epochs 반복 차수가 높아질수록 train과 validation 셋의 성능이 차이가 커진다. -> overfitting문제가 있으나 성능 자체가 낮아 test셋에 대해 비슷한 성능을 보임

----------------------------------------
### CNN - basic

* 데이터 : 위와 동일

* 모델 구조
  * 입력레이어 1, 합성곱 레이어(각 층마다 MaxPooling 적용) 4, Flatten 1, 은닉레이어 1, 출력레이어 1
  * train : 40000, validation : 10000
  * Padding : 사용, strides : 1 또는 2 사용, 활성화함수 : LeakyReLU, 출력층 활성화함수 : softmax, BatchNormalization : 사용안함, Dropout : 사용안함, Maxpooling : 사용안함

* 모델 성능
  * 훈련셋 : loss: 0.3046 - accuracy: 0.8922 - val_loss: 1.1999 - val_accuracy: 0.6995
  * 테스트셋 : loss: 1.2336 - accuracy: 0.6932

-train셋에 대한 예측 지표보다 validation와 test의 지표가 현저히 낮음. -> overfitting 문제가 심함
-DNN보다 전반적으로 좋은 성능을 보이는 것으로 확인 -> 이미지 분류에 있어서 DNN보다 성능이 좋다.

* 학습 모델 그래프

<img src = "https://user-images.githubusercontent.com/72690336/118844008-90c90400-b905-11eb-8d8e-c2ba3e159943.png" width="40%" height="40%">  <img src = "https://user-images.githubusercontent.com/72690336/118844100-a63e2e00-b905-11eb-9efa-27a4d3008b92.png" width="40%" height="40%">

-epochs 반복 차수가 높아질수록 validation의 성능은 오히려 떨어진다. -> 과적합으로 인한 새로운 데이터 분류 불가능

----------------------------------------
### CNN - Dropdout, BatchNormalization

* 데이터 : 위와 동일

* 모델 구조
  * 입력레이어 1, 합성곱 레이어(각 층마다 MaxPooling 적용) 4, Flatten 1, 은닉레이어 1, 출력레이어 1
  * train : 40000, validation : 10000
  * Padding : 사용, strides : 1 또는 2 사용, 활성화함수 : LeakyReLU, 출력층 활성화함수 : softmax, BatchNormalization : 첫번째 합성곱 레이어에 적용, Dropout : 두번째부터 모든 층에 적용, Maxpooling : 사용안함

* 모델 성능
  * 훈련셋 : loss: 0.9262 - accuracy: 0.6748 - val_loss: 0.9314 - val_accuracy: 0.6731
  * 테스트셋 : loss: 0.9388 - accuracy: 0.6694

-train셋과 validation셋의 성능이 비슷함 -> overfitting 문제 해결
-전체적인 loss값은 내려갔지만 분류 정확도는 다소 낮아짐 -> 모델의 축소로 인한 성능 저하로 의심

* 학습 모델 그래프

<img src = "https://user-images.githubusercontent.com/72690336/118845406-b4d91500-b906-11eb-8a4b-5b43a5393293.png" width="40%" height="40%">  <img src = "https://user-images.githubusercontent.com/72690336/118845478-c7ebe500-b906-11eb-9dc0-f17f44df72de.png" width="40%" height="40%">

-epochs 반복 차수가 높아질수록 성능이 좋아지는 것을 확인할 수 있음. -> 모델 성능의 개선을 위해 더 많은 레이어추가와 epochs 값 증대
-validation셋의 성능이 매 회차 반복마다 심하게 흔들리는 것을 확인. 아직 원인을 알 수 없어 더 큰 epochs 값을 통한 시행으로 확인할 필요가 있다.

---------------------------------------------

### 최종 모델

* 데이터 : 위와 동일

* 모델 구조
  * 입력레이어 1, 합성곱 레이어(각 층마다 MaxPooling 적용) 4, Flatten 1, 은닉레이어 1, 출력레이어 1
  * train : 50000, validation : 10000
  * Padding : 사용, strides : 1 또는 2 사용, 활성화함수 : LeakyReLU, 출력층 활성화함수 : softmax, BatchNormalization : 첫번째 합성곱 레이어에 적용, Dropout : 두번째부터 모든 층에 적용, Maxpooling : 합성곱 레이어 연산이 모두 끝난 후 Flatten 레이어에 전달하기 전 적용, ImageDataGenerator : 적용

* Data augmentation
  * 데이터를 조금씩 변형시킨 이미지 반영하여 부풀림
  * ImageDataGenerator(rotation_range=0.1, width_shift_range=0.1, height_shift_range=0.1, horizontal_flip=True)
  * width_shift_range, height_shift_range : 이미지를 위아래, 양 옆으로 조금씩 이동
  * rotation_range : 이미지를 회전
  * horizontal_flip : 이미지를 뒤집는다.

* 모델 성능
  * 훈련셋 : loss: 0.9033 - accuracy: 0.6818 - val_loss: 0.8401 - val_accuracy: 0.7175
  * 테스트셋 : loss: 0.8401 - accuracy: 0.7175

-Data Augmentation을 적용한 결과 분류 성능이 다소 상승.
-test셋에 대한 성능이 validation과 완전 똑같음. -> 뭔가가 잘못된 것 같다. 다시한번 시행 후 결과 비교

* 학습 모델 그래프

<img src = "https://user-images.githubusercontent.com/72690336/118837577-edc1bb80-b8ff-11eb-8435-386572ed52b9.png" width="40%" height="40%">  <img src = "https://user-images.githubusercontent.com/72690336/118837658-0336e580-b900-11eb-95aa-194f36102a91.png" width="40%" height="40%">

-validation 셋의 성능이 급격히 하락하는 시점이 존재함.
-전반적 모델을 반복 수행함에 따라 성능이 점점 개선됨. -> 더 많은 레이어와 반복 수행 후 결과 비교

* 최종 예측 샘플

<img src = "https://user-images.githubusercontent.com/72690336/118848583-d8ea2580-b909-11eb-9591-f93894634d20.png" width="40%" height="40%">


----------------------------------------

### 개선할 점

* 중간중간 validation 셋의 성능이 크게 상승과 하락을 반복하는 원인파악
* dropout, batchnormalization, maxpooling, ImageDataAugmentation을 따로 시행한 후 결과 비교
