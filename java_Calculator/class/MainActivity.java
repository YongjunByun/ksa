package com.example.calculator;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.View;
import java.util.Random;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Switch;
import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {


    //버튼 and 텍스트뷰
    Button btn0, btn1, btn2, btn3, btn4, btn5, btn6, btn7, btn8, btn9, btndot;
    Button btn_reset, btn_dice, btn_del, btn_start, btn_end, btn_result;
    Button btn_add, btn_sub, btn_mul, btn_div, btn_mod, btn_sqrt, btn_squared, btn_exp, btn_log, btn_factorial;
    TextView input_show, result_show;

    Operate_Process op;
    String operExpression, input;
    Double result;

    ArrayList<String> post;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        //버튼 리스너

        init();
        setNumListener();
        setOperationListener();
        setResultListener();

    }

    void init(){
        //리소스 연결
        //숫자 and . 버튼
        btn0 = (Button) findViewById(R.id.btn0);
        btn1 = (Button) findViewById(R.id.btn1);
        btn2 = (Button) findViewById(R.id.btn2);
        btn3 = (Button) findViewById(R.id.btn3);
        btn4 = (Button) findViewById(R.id.btn4);
        btn5 = (Button) findViewById(R.id.btn5);
        btn6 = (Button) findViewById(R.id.btn6);
        btn7 = (Button) findViewById(R.id.btn7);
        btn8 = (Button) findViewById(R.id.btn8);
        btn9 = (Button) findViewById(R.id.btn9);
        btndot = (Button) findViewById(R.id.btndot);

        //괄호, 지우기, 삭제, 주사위, = 버튼
        btn_reset = (Button) findViewById(R.id.btn_reset);
        btn_dice = (Button) findViewById(R.id.btn_dice);
        btn_del = (Button) findViewById(R.id.btn_del);
        btn_start = (Button) findViewById(R.id.btn_start);
        btn_end = (Button) findViewById(R.id.btn_end);
        btn_result = (Button) findViewById(R.id.btn_result);

        //연산자
        btn_add = (Button) findViewById(R.id.btn_add);
        btn_sub = (Button) findViewById(R.id.btn_sub);
        btn_mul = (Button) findViewById(R.id.btn_mul);
        btn_div = (Button) findViewById(R.id.btn_div);
        btn_mod = (Button) findViewById(R.id.btn_mod);
        btn_log = (Button) findViewById(R.id.btn_log);
        btn_exp = (Button) findViewById(R.id.btn_exp);
        btn_sqrt = (Button) findViewById(R.id.btn_sqrt);
        btn_squared = (Button) findViewById(R.id.btn_squared);
        btn_factorial = (Button) findViewById(R.id.btn_factorial);

        //결과
        result_show = (TextView) findViewById(R.id.result_show);
        //입력수식
        input_show = (TextView) findViewById(R.id.input_show);

        op = new Operate_Process();

        //변수 초기화
        operExpression = "";
        input = "";
        result = 0.0;

        post = new ArrayList<String>();
    }

    Random random;
    void setNumListener(){

        //숫자 버튼 클릭 시
        View.OnClickListener NumListener = new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                switch (view.getId()){
                    case R.id.btn0:
                        input += "0";
                        operExpression += "0";
                        break;

                    case R.id.btn1:
                        input += "1";
                        operExpression += "1";
                        break;

                    case R.id.btn2:
                        input += "2";
                        operExpression += "2";
                        break;

                    case R.id.btn3:
                        input += "3";
                        operExpression += "3";
                        break;

                    case R.id.btn4:
                        input += "4";
                        operExpression += "4";
                        break;

                    case R.id.btn5:
                        input += "5";
                        operExpression += "5";
                        break;

                    case R.id.btn6:
                        input += "6";
                        operExpression += "6";
                        break;

                    case R.id.btn7:
                        input += "7";
                        operExpression += "7";
                        break;

                    case R.id.btn8:
                        input += "8";
                        operExpression += "8";
                        break;

                    case R.id.btn9:
                        input += "9";
                        operExpression += "9";
                        break;

                    case R.id.btndot:
                        input += ".";
                        operExpression += ".";
                        break;

                    case R.id.btn_dice:
                        random = new Random();
                        int a = random.nextInt(100);
                        input += a+"";
                        operExpression += a+"";
                        break;
                }
                //연산식 출력

                result_show.setText(operExpression);

            }
        };
        btn0.setOnClickListener(NumListener);
        btn1.setOnClickListener(NumListener);
        btn2.setOnClickListener(NumListener);
        btn3.setOnClickListener(NumListener);
        btn4.setOnClickListener(NumListener);
        btn5.setOnClickListener(NumListener);
        btn6.setOnClickListener(NumListener);
        btn7.setOnClickListener(NumListener);
        btn8.setOnClickListener(NumListener);
        btn9.setOnClickListener(NumListener);
        btndot.setOnClickListener(NumListener);
        btn_dice.setOnClickListener(NumListener);
    }

    void setOperationListener(){
        View.OnClickListener OperationListener = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                switch(view.getId()){
                    case R.id.btn_add:
                        input += "+";
                        operExpression += "+";
                        break;

                    case R.id.btn_sub:
                        input += "-";
                        operExpression += "-";
                        break;

                    case R.id.btn_mul:
                        input += "*";
                        operExpression += "*";
                        break;

                    case R.id.btn_div:
                        input += "/";
                        operExpression += "/";
                        break;

                    case R.id.btn_mod:
                        input += "%";
                        operExpression += "%";
                        break;

                    case R.id.btn_log:
                        input += "l";
                        operExpression += "LOG";
                        break;

                    case R.id.btn_exp:
                        input += "e";
                        operExpression += "EXP";
                        break;

                    case R.id.btn_sqrt:
                        input += "√";
                        operExpression += "√";
                        break;

                    case R.id.btn_squared:
                        input += "^";
                        operExpression += "^";
                        break;

                    case R.id.btn_factorial:
                        input += "!";
                        operExpression += "!";
                        break;

                    case R.id.btn_start:
                        input += "(";
                        operExpression += "(";
                        break;

                    case R.id.btn_end:
                        input += ")";
                        operExpression += ")";
                        break;

                    case R.id.btn_del:
                        if(input.length()>=1){
                            input = input.substring(0, input.length()-1);
                            operExpression = operExpression.substring(0,operExpression.length()-1);
                        }
                        break;

                    case R.id.btn_reset:
                        input = "";
                        operExpression = "0";
                        input_show.setText("");
                        break;

                }
                result_show.setText(operExpression);
            }
        };

        btn_add.setOnClickListener(OperationListener);
        btn_sub.setOnClickListener(OperationListener);
        btn_mul.setOnClickListener(OperationListener);
        btn_div.setOnClickListener(OperationListener);
        btn_mod.setOnClickListener(OperationListener);
        btn_log.setOnClickListener(OperationListener);
        btn_exp.setOnClickListener(OperationListener);
        btn_sqrt.setOnClickListener(OperationListener);
        btn_squared.setOnClickListener(OperationListener);
        btn_factorial.setOnClickListener(OperationListener);
        btn_start.setOnClickListener(OperationListener);
        btn_end.setOnClickListener(OperationListener);
        btn_reset.setOnClickListener(OperationListener);
        btn_del.setOnClickListener(OperationListener);
    }
    void setResultListener(){
        View.OnClickListener ResultListener = new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (view.getId() == R.id.btn_result){
                    operExpression += "=";
                    post = op.to_postfix(input);
                    result = op.operate(post);
                    input_show.setText(operExpression);
                    result_show.setText(result + "");
                    input = result+"";
                    operExpression = result+"";

                }

            }
        };
        btn_result.setOnClickListener(ResultListener);
    }
}