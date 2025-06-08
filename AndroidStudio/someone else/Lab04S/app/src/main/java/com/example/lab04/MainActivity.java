package com.example.lab04;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import android.view.View;
import android.widget.CheckBox;
import android.widget.CompoundButton;
import android.widget.LinearLayout;
import android.widget.RadioGroup;
import android.widget.ToggleButton;
import android.widget.ImageButton;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    private LinearLayout hiddenBtns;
    private RadioGroup colors;
    private CheckBox colorBg;
    private TextView ratingText;
    private ImageButton star1, star2, star3, star4, star5;
    int activeColorId;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        ToggleButton showHideBtns = findViewById(R.id.showExtra);

        activeColorId = R.color.green;

        colors = findViewById(R.id.colors);
        hiddenBtns = findViewById(R.id.hiddenBtns);
        ratingText = findViewById(R.id.ratingText);
        colorBg = findViewById(R.id.colorBg);

        star1 = findViewById(R.id.star1);
        star2 = findViewById(R.id.star2);
        star3 = findViewById(R.id.star3);
        star4 = findViewById(R.id.star4);
        star5 = findViewById(R.id.star5);


        showHideBtns.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if (b) hiddenBtns.setVisibility(View.VISIBLE);
                else hiddenBtns.setVisibility(View.INVISIBLE);
            }
        });

        colorBg.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton compoundButton, boolean b) {
                if (b) hiddenBtns.setBackgroundColor(getResources().getColor(activeColorId));
                else hiddenBtns.setBackgroundColor(getResources().getColor(R.color.white));
            }
        });

        colors.setOnCheckedChangeListener(new RadioGroup.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(RadioGroup radioGroup, int i) {
                if (colors.getCheckedRadioButtonId() == R.id.red) activeColorId = R.color.red;
                else if (colors.getCheckedRadioButtonId() == R.id.green) activeColorId = R.color.green;
                else if (colors.getCheckedRadioButtonId() == R.id.blue) activeColorId = R.color.blue;

                if (colorBg.isChecked()) hiddenBtns.setBackgroundColor(getResources().getColor(activeColorId));
            }
        });

        star1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                star1.setImageResource(android.R.drawable.btn_star_big_on);
                star2.setImageResource(android.R.drawable.btn_star_big_off);
                star3.setImageResource(android.R.drawable.btn_star_big_off);
                star4.setImageResource(android.R.drawable.btn_star_big_off);
                star5.setImageResource(android.R.drawable.btn_star_big_off);

                ratingText.setText("Painful :(");
            }
        });

        star2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                star1.setImageResource(android.R.drawable.btn_star_big_on);
                star2.setImageResource(android.R.drawable.btn_star_big_on);
                star3.setImageResource(android.R.drawable.btn_star_big_off);
                star4.setImageResource(android.R.drawable.btn_star_big_off);
                star5.setImageResource(android.R.drawable.btn_star_big_off);

                ratingText.setText("Just a smidge better than 1");
            }
        });

        star3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                star1.setImageResource(android.R.drawable.btn_star_big_on);
                star2.setImageResource(android.R.drawable.btn_star_big_on);
                star3.setImageResource(android.R.drawable.btn_star_big_on);
                star4.setImageResource(android.R.drawable.btn_star_big_off);
                star5.setImageResource(android.R.drawable.btn_star_big_off);

                ratingText.setText("Golden mean I guess?");
            }
        });

        star4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                star1.setImageResource(android.R.drawable.btn_star_big_on);
                star2.setImageResource(android.R.drawable.btn_star_big_on);
                star3.setImageResource(android.R.drawable.btn_star_big_on);
                star4.setImageResource(android.R.drawable.btn_star_big_on);
                star5.setImageResource(android.R.drawable.btn_star_big_off);

                ratingText.setText("Just a bit more to improve!");
            }
        });

        star5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                star1.setImageResource(android.R.drawable.btn_star_big_on);
                star2.setImageResource(android.R.drawable.btn_star_big_on);
                star3.setImageResource(android.R.drawable.btn_star_big_on);
                star4.setImageResource(android.R.drawable.btn_star_big_on);
                star5.setImageResource(android.R.drawable.btn_star_big_on);

                ratingText.setText("Perfect! c:");
            }
        });
    }


}