package com.example.calculator;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Stack;

public class Operate_Process extends Operator{

    //연산자 검사
    boolean isOperator(String s){

        return super.priority.containsKey(s);
    }

    Stack<String> postfix;
    ArrayList<String> arr;
    String num;
    //입력 수식 후위표기식으로 변환
    ArrayList<String> to_postfix(String s){
        //출력배열
        arr = new ArrayList<String>();

        //operand
        num = "";

        //후위 표기식 생성 스택
        postfix = new Stack<String>();

        //연산자와 숫자 분류
        for (int i = 0; i< s.length(); i++){
            char op = s.charAt(i);

            //분류 후 연산자일때
            if(isOperator(op+"")){
                //연산자가 나오면 이전에 나온 숫자 출력
                if(num != ""){
                    arr.add(num);
                    num = "";
                }

                //스택이 비어있거나 '('일 때
                if(postfix.isEmpty() || op == '(') {
                    postfix.push(op + "");

                } else {

                    //우선순위 : top < token
                    if(super.priority.get(postfix.peek()) > super.priority.get(op+"")){
                        postfix.push(op + "");

                        //우선순위 : top >= token
                    } else {
                        while(true){
                            if(postfix.isEmpty()) {
                                postfix.push(op + "");
                                break;
                            } else if(super.priority.get(postfix.peek()) <= super.priority.get(op+"")){
                                arr.add(postfix.pop());
                            } else {
                                postfix.push(op + "");
                                break;
                            }
                        }
                    }
                }
                //토큰이 오른쪽 괄호
            } else if(op==')'){
                if(num != ""){
                    arr.add(num);
                    num = "";
                }
                while(true){
                    if(postfix.peek().equals("(")){
                        postfix.pop();
                        break;
                    }
                    arr.add(postfix.pop());
                }
                //토큰이 숫자일때 연산자가 나올때까지 숫자 read
            } else {
                num += op + "";
            }
        }
        //마지막 숫자 추가
        arr.add(num);
        //스택에 남은 연산자 모두 pop
        while(true){
            if(postfix.isEmpty()){
                break;
            }
            arr.add(postfix.pop());
        }
        arr.remove("");
        return arr;
    }

    Stack<Double> sum;
    //후위표현식을 이용한 연산 수행
    double operate(ArrayList<String> arr){
        int len = arr.size();
        sum = new Stack<Double>();

        int i = 0;
        double p, q;
        while(i<len){
            if(arr.get(i).equals("+")){
                q = sum.pop();
                p = sum.pop();
                sum.add(super.plus(p,q));
            } else if(arr.get(i).equals("-")){
                q = sum.pop();
                p = sum.pop();
                sum.add(super.sub(p,q));
            } else if(arr.get(i).equals("*")){
                q = sum.pop();
                p = sum.pop();
                sum.add(super.mul(p,q));
            } else if(arr.get(i).equals("/")){
                q = sum.pop();
                p = sum.pop();
                sum.add(super.div(p,q));
            } else if(arr.get(i).equals("%")){
                q = sum.pop();
                p = sum.pop();
                sum.add(super.mod(p,q));
            } else if(arr.get(i).equals("l")){
                p = sum.pop();
                sum.add(super.log(p));
            } else if(arr.get(i).equals("e")){
                p = sum.pop();
                sum.add(super.exp(p));
            } else if(arr.get(i).equals("^")){
                q = sum.pop();
                p = sum.pop();
                sum.add(super.square(p,q));
            } else if(arr.get(i).equals("√")){
                p = sum.pop();
                sum.add(super.sqrt(p));
            } else if(arr.get(i).equals("!")){
                p = sum.pop();
                sum.add(super.factorial(p));
            } else{
                sum.add(Double.parseDouble(arr.get(i)));
            }
            i++;
        }
        return sum.pop();
    }
}


