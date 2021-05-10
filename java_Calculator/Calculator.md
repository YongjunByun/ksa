# [자바 프로젝트]
###### 날짜: 2020.05.10 | 작정자: 정시원 | Version: 1.0

## 1. 요구사항 분석 (Requirement Analysis)
<strong> * 공학용 계산기 구현
* Android Studio 사용
* 덧셈, 뺄셈, 곱셈, 나눗셈, 나머지, 로그, 지수, 제곱, 루트, 팩토리얼 연산 구현
* 실수 연산 구현
* RESET, DICE(RANDOM INT), DEL 버튼 구현
* "=" 클릭 시 결과 및 연산 식 출력


## 2. 구조 설계
### 1) UML(Unified Modeling Language) Diagram
#### (1) Use Case Diagram
![유스케이스다이어그램](https://user-images.githubusercontent.com/72690336/117634518-f278c800-b1b9-11eb-9dcd-a95ed87272e7.jpg)

#### (2) Sequence Diagram
![시퀀스다이어그램](https://user-images.githubusercontent.com/72690336/117635238-98c4cd80-b1ba-11eb-9899-3cb02154d4c1.JPG)

#### (3) Class Diagram
![클래스다이어그램](https://user-images.githubusercontent.com/72690336/117635746-17ba0600-b1bb-11eb-944c-014e41ab6441.JPG)

### 2) 클래스 정의
<strong> * Operator Class
  * 필드 : 연산자 우선순위 HashMap
  * 메소드 : 실수형 연산자(+, -, *, /, %, log, exp, !, ^, √)

<strong> * Operate_Process Class
  * 필드 : 변환한 후위표기식 ArrayList<String>, 연산자 Stack, 피연산자 String, 연산결과 Stack<Double>
  * 메소드 : 연산자 검사(isOperator), 후위표기식 변환(to_postfix), 후위표기식 연산(operate)

<strong> * MainActivity Class
  * 필드 : 버튼 위젯 id 선언, 텍스트뷰 위젯 id 선언, 입력 수식 String, 결과값 Double, 출력 수식 String, Operate_Process 클래스 선언,
  * 메소드 : 생성자 메소드(onCreate), 초기화 메소드(init), 리스너메소드(setNumListener, setOperationListener, setResultListener)

### 3) 기능
<strong> * Operator Class
  * plus 메소드 : 입력된 숫자 2개를 사용하여 덧셈
  * sub 메소드 : 입력된 숫자 2개를 사용하여 뺄셈
  * mul 메소드 : 입력된 숫자 2개를 사용하여 곱셈
  * div 메소드 : 입력된 숫자 2개를 사용하여 나눗셈
  * mod 메소드 : 입력된 숫자 2개를 사용하여 나머지계산
  * 
