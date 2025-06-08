package com.example.lab04;

import androidx.appcompat.app.AppCompatActivity;

import android.graphics.Color;
import android.os.Bundle;

import android.util.Log;
import android.view.View;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.RadioGroup;
import android.widget.ToggleButton;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private RadioGroup states;
    private RadioGroup colors;
    private ToggleButton extraBtn;
    private CheckBox showPos;
    private TextView pos;
    private ImageView moon;
    private ImageButton zoomIn;
    private ImageButton zoomOut;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        states = findViewById(R.id.states);
        colors = findViewById(R.id.colors);
        extraBtn = findViewById(R.id.showExtra);

        showPos = findViewById(R.id.showPos);
        pos = findViewById(R.id.posText);

        moon = findViewById(R.id.moon);

        zoomIn = findViewById(R.id.zoomIn);
        zoomOut = findViewById(R.id.zoomOut);

        extraBtn.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if (b) colors.setVisibility(View.VISIBLE);
                else colors.setVisibility(View.INVISIBLE);
            }
        });

        showPos.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if (pos.getVisibility() == View.INVISIBLE) pos.setVisibility(View.VISIBLE);
                else pos.setVisibility(View.INVISIBLE);
            }
        });

        states.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup radioGroup, int i) {
                int state = states.getCheckedRadioButtonId();
                int color = colors.getCheckedRadioButtonId();

                if (state == R.id.wan) {
                    if (color == R.id.white) moon.setImageResource(R.drawable.w_wan);
                    else if (color == R.id.blue) moon.setImageResource(R.drawable.b_wan);
                    else if (color == R.id.red) moon.setImageResource(R.drawable.r_wan);
                }
                else if (state == R.id.wax) {
                    if (color == R.id.white) moon.setImageResource(R.drawable.w_wax);
                    else if (color == R.id.blue) moon.setImageResource(R.drawable.b_wax);
                    else if (color == R.id.red) moon.setImageResource(R.drawable.r_wax);
                }
                else if (state == R.id.newmoon) moon.setImageResource(R.drawable.new_moon);
                else if (state == R.id.fullmoon) {
                    if (color == R.id.white) moon.setImageResource(R.drawable.w_full);
                    else if (color == R.id.blue) moon.setImageResource(R.drawable.b_full);
                    else if (color == R.id.red) moon.setImageResource(R.drawable.r_full);
                }

                isMoonOk();
            }
        });

        colors.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup radioGroup, int i) {
                int state = states.getCheckedRadioButtonId();
                int color = colors.getCheckedRadioButtonId();

                if (state == R.id.wan) {
                    if (color == R.id.white) moon.setImageResource(R.drawable.w_wan);
                    else if (color == R.id.blue) moon.setImageResource(R.drawable.b_wan);
                    else if (color == R.id.red) moon.setImageResource(R.drawable.r_wan);
                }
                else if (state == R.id.wax) {
                    if (color == R.id.white) moon.setImageResource(R.drawable.w_wax);
                    else if (color == R.id.blue) moon.setImageResource(R.drawable.b_wax);
                    else if (color == R.id.red) moon.setImageResource(R.drawable.r_wax);
                }
                else if (state == R.id.newmoon) moon.setImageResource(R.drawable.new_moon);
                else if (state == R.id.fullmoon) {
                    if (color == R.id.white) moon.setImageResource(R.drawable.w_full);
                    else if (color == R.id.blue) moon.setImageResource(R.drawable.b_full);
                    else if (color == R.id.red) moon.setImageResource(R.drawable.r_full);
                }

                isMoonOk();
            }
        });

        zoomIn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moon.getScaleX() < 2.0f) {
                    moon.setScaleX(moon.getScaleX() + 0.1f);
                    moon.setScaleY(moon.getScaleX());
                }
            }
        });

        zoomOut.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (moon.getScaleX() > 1.0f) {
                    moon.setScaleX(moon.getScaleX() - 0.1f);
                    moon.setScaleY(moon.getScaleX());
                }
            }
        });
    }

    public void isMoonOk() {
        if (states.getCheckedRadioButtonId() == R.id.newmoon) {
            pos.setText("Луна упала!");
            pos.setTextColor(Color.parseColor("#F44336"));
        }
        else {
            pos.setText("Луна ещё не упала");
            pos.setTextColor(Color.parseColor("#4CAF50"));
        }
    }
}