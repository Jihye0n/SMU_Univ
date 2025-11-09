package com.example.myapplication6;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    EditText edt;
    Button btn;
    TextView text;
    String inputText;

    @Override
    protected void onCreate(Bundle savedInstanceState) { // 화면에 보여준다.
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main); // 화면에 보여준다.

        // 손코딩 (중간고사!)
        LinearLayout.LayoutParams params = new LinearLayout.LayoutParams(
                LinearLayout.LayoutParams.MATCH_PARENT,
                LinearLayout.LayoutParams.MATCH_PARENT);

        LinearLayout baseLayout = new LinearLayout(this); // baseLayout 을 만든다.
        baseLayout.setOrientation(LinearLayout.VERTICAL); // baseLayout을 vertical로 설정 (orientation 등록)
        baseLayout.setBackgroundColor(Color.rgb(255,255,255));
        setContentView(baseLayout, params); // 화면에 보여준다.

        edt = new EditText(this);
        edt.setText("여기에 입력하세요");
        baseLayout.addView(edt);

        btn = new Button(this);
        btn.setText("버튼입니다.");
        btn.setBackgroundColor(Color.YELLOW);
        baseLayout.addView(btn);

        text = new TextView(this);
        text.setText("");
        text.setTextColor(Color.RED);
        baseLayout.addView(text);

        btn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Toast.makeText(getApplicationContext(), "코드로 생성한 버튼입니다.", Toast.LENGTH_SHORT).show();
                inputText = edt.getText().toString();
                text.setText(inputText);
            }
        });
    }
}