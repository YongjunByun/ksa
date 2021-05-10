package com.example.calculator;

import java.util.Random;
import java.util.HashMap;

public class Operator {

    public HashMap<String, Integer> priority;

    {
        /* 우선순위 해쉬 맵*/
        priority = new HashMap<>();
        priority.put("(",4);
        priority.put("!",1);
        priority.put("e",1);
        priority.put("l",1);
        priority.put("√",1);
        priority.put("^",2);
        priority.put("*",2);
        priority.put("/",2);
        priority.put("%",2);
        priority.put("+",3);
        priority.put("-",3);
    }

    //사칙연산
    //덧셈
    public double plus(double x, double y) { return x+y; }

    //뺄셈
    public double sub(double x, double y) { return x-y; }

    //곱셈
    public double mul(double x, double y) { return x*y; }

    //나눗셈
    public double div(double x, double y) { return x/y; }

    //나머지
    public double mod(double x, double y) { return x%y; }

    //상용로그
    public double log(double x) { return Math.log10(x); }

    //지수
    public double exp(double x) { return Math.exp(x); }

    //제곱
    public double square(double x, double y) { return Math.pow(x,y);}

    //루트
    public double sqrt(double x) { return Math.sqrt(x); }

    //팩토리얼
    public double factorial(double x) {
        if(x<=1) {
            return 1;
        } else {
            return factorial(x-1) * x;
        }
    }

    //주사위
    public double randnum(double x) {
        Random rd = new Random();//랜덤 객체 생성
        return rd.nextInt(100); //1~100사이 랜덤 정수
    }
}
