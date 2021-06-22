# GAN과 시각지능
###### <strong> GAN의 기본 - Vanilla GAN

* 언어 : Python
* 프로그램 : Colab
* 소스코드 : GAN.ipynb
* 사용한 모듈 : matplotlib, torch, torchvison, tqdm
* 주요 함수 :

```

 gen_block, dis_block, class Generator, class Discriminator, get_gen_loss, get_disc_loss, show_tensor_images
 
 ```
 

----------------------------------------

## 데이터

* MNIST

----------------------------------------

## GAN
 
### GAN의 기본원리
 
 * 적대적 탐색(Adversarial search) : 서로 반대되는 두 입장의 객체가 서로 입장을 바꿔가며 진행함으로써 최적의 해를 탐색하는 과정
 
 * Discriminator Model(Classifier) : 입력 데이터를 미리 정의한 카테고리로 분류
   * SVM -> CNN
   * 입력 : 복잡한 모델 ex) 영상
   * 출력 : 하나의 scalar or n 개의 class
 
 * Generative Model : 간단한 정보(latent vector)로부터 복잡한 모델을 합성하는 도구
   * AE(Auto Encoder) -> VAE(Variational Auto Encoder)
   * 입력 : 간단한 정보(latent vector)
   * 출력 : 영상
 
 <p align="center"><img src = "https://user-images.githubusercontent.com/72690336/122800405-dbbbaa00-d2fd-11eb-8688-a05e8eaef6b1.png" width="80%" height="80%">

  
### GAN의 개념
  
  * 생성자 (Generator)와 판별자 (Discriminator)의 대립과 경쟁을 통해서 모델을 훈련시켜서 사용자가 만족할만한 수준의 결과를 생성하는 생성 모델
  * 생성자 (Generator)
    * G::p<sub>z</sub>(z) -> p<sub>g</sub>
    * 대립을 통해 더 우수한 품질의 결과 도출하도록 훈련
  * 판별자 (Discriminator)
    * D::D(x;𝜃<sub>d</sub> -> fake/real
    * 생성자의 결과가 만족할 수준인지를 판별하여 fake/real의 결과 도출
   * x ~ p<sub>g</sub> -> fake, x ~ data -> real
  * GAN의 훈련이 끝나면 마지막 parameter(𝜃<sub>g</sub>)를 저장한 generator를 이용해서 다양한 샘플 생성
  
 <p align="center"><img src = "https://user-images.githubusercontent.com/72690336/122802940-f7747f80-d300-11eb-8afb-6524d4d1a7df.png" width="40%" height="40%">
  
### GAN의 구성요소
  * 생성자(Generator)
    * Decoder와 유사한 구조
    * 입력(latent vector)를 받아서 결과(synthesized image)를 생성하는 모듈
    * Vanilla Gan에서는 convolution을 사용하지 않음
  
  * Generator의 구조
    * n개의 generator block 으로 구성
    * generator block은 낮은 해상도의 입력을 받아서 높은 해상도의 출력을 생성
  
  <p align="center"><img src = "https://user-images.githubusercontent.com/72690336/122803575-bdf04400-d301-11eb-8764-c1f8b0faf957.png" width="70%" height="70%">
  
  * 판별자(Discriminator)
    * 입력(real or fake data)을 받아서 real/fake를 판정하는 모듈
    * Classifier와 유사한 역할을 수행
   
  * Discriminator의 구조
    * n개의 discriminator block 으로 구성
    * discriminator block은 높은 해상도의 입력을 받아서 낮은 해상도의 출력을 생성
   
   <p align="center"><img src = "https://user-images.githubusercontent.com/72690336/122804041-58e91e00-d302-11eb-974e-995c385319db.png" width="70%" height="70%">
    
  * GAN Loss 함수
    * BCE(Binary Cross Entropy에서 도출
    * 훈련데이터 (real, x) -> y<sup>(i)</sup> = 1
    * 생성데이터 (fake, G(z)) -> y<sup>(i)</sup> = 0, x<sup>(i)</sup> = G(z<sup>(i)</sup>, 𝜃<sub>g</sub>)
    * Discriminator -> h(.,𝜃<sub>d</sub>
    * BCE와의 차이 : BCE는 최대화하는 𝜃 하나를 찾는 문제로 max 방향으로만 최적화 하기 때문에 훈련이 쉬우나, GAN Loss는 max와 min 방향으로 최적화하기 때문에 훈련이 어려움
      * Discriminator: D(x)는 1을, D(G(z))는 0을 출력할 것 -> logD(x) & log (1 – D(G(z)))가 max
      * Generator: D(G(z))가 1을 출력할 것 -> log(1 – D(G(z)))가 min
    
    <p align="center"><img src = "https://user-images.githubusercontent.com/72690336/122806282-1bd25b00-d305-11eb-89df-08d747d637ae.png" width="70%" height="70%">

    
### GAN Training
  * 훈련 목표
    * 훈련 데이터 x와 일치하는 G(z)를 생성하는 것 P<sub>data</sub> = P<sub>z</sub>, 잘 생성되면 D()는 x와 G(z)를 구분하지 못함 = 값 : 1/2
    * GAN은 min max V(G,D)를 추구하기 때문에 수렴이 어려울 수 있지만, 최적의 경우에 수렴되는 값이 있음을 증명
    
  * 훈련의 어려움
    * D와 G를 동시에 훈련해야함 : D는 max, G는 min을 추구
    * 훈련 초기 생성되는 G(z)는 품질이 안좋은 -> 매번 0에 가까우면 log(1-D(G(z))이 0에 가까운 값을 가짐 -> gradient descent를 적용하기 힘듦
    * 위와 같은 문제을 방지하기 위해 초기에는 log(1-D(G(z))를 사용하지 말고 D(G(z))를 최대화 시키는 방향으로 훈련(후자가 값이 더 크다)

---------------------------------------------


### 코드 설명

* generator block
   ```python
      def gen_block(input_dim, output_dim):
       return nn.Sequential(
         nn.Linear(input_dim, output_dim),
         nn.BatchNorm1d(output_dim),
         nn.ReLU(inplace=True),
       )
     ```
  * input 차원과 output 차원을 입력받음
  * Linear layer와 batch norm, relu 함수로 구성
     
* Generator
     ```python
        class Generator(nn.Module):
         def __init__(self, z_dim=10, im_dim=784, hidden_dim=128):
           super(Generator, self).__init__()
           # Build the neural network
           self.gen = nn.Sequential(
               gen_block(z_dim, hidden_dim),
               gen_block(hidden_dim, hidden_dim*2),
               gen_block(hidden_dim*2, hidden_dim*4),
               gen_block(hidden_dim*4, hidden_dim*8),

               nn.Linear(hidden_dim*8, im_dim),
               nn.Sigmoid()
           )
     ```
  * 4개의 generator block과 FC layer, sigmoid 함수로 구성
  * MNIST데이터 입력(28x28)
    * 입력 : z_dim = 10
    * 출력 : im_dim = 784
     
* discriminator block
   ```python
      def dis_block(input_dim, output_dim):
       return nn.Sequential(
         nn.Linear(input_dim, output_dim),
         nn.LeakyReLU(0.2, inplace=True)
       )
     ```
  * input 차원과 output 차원을 입력받음
  * Linear layer와 relu 함수로 구성
     
* Discriminator
  ```python
     class Discriminator(nn.Module):
      def __init__(self, im_dim=784, hidden_dim=128):
        super(Discriminator, self).__init__()
        self.disc = nn.Sequential(
            dis_block(im_dim, hidden_dim * 4),
            dis_block(hidden_dim * 4, hidden_dim * 2),
            dis_block(hidden_dim * 2, hidden_dim),
            nn.Linear(hidden_dim, 1)
        )
     ```
  * 3개의 discriminator block과 FC layer로 구성
  * MNIST데이터 입력(28x28)
    * 입력 : im_dim = 784
    * 출력 : 1
     
* 이후 Loss Function 정의, 초기화, Optimizer 생성, 모델 Training 순으로 진행
     
     <p align="center"><img src = "https://user-images.githubusercontent.com/72690336/122808601-0dd20980-d308-11eb-89b8-32fa62903301.png" width="30%" height="30%">
      
      
### 샘플 이미지
* 원본 이미지(real)
      
<p align="center"><img src = "https://user-images.githubusercontent.com/72690336/122808816-4eca1e00-d308-11eb-8eb3-ab3a3777fcd6.png" width="30%" height="30%">

* 생성이미지(fake)
 
<p align="center"><img src = "https://user-images.githubusercontent.com/72690336/122809052-8df86f00-d308-11eb-863f-3ab343d2f733.png" width="30%" height="30%">
 
* 모델 성능(step 6000)
  * Generator loss: 3.7584004163742075, discriminator loss: 0.07491180759668352

