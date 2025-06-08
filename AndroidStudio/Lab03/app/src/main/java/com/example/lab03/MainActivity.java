package com.example.lab03;

import androidx.appcompat.app.AppCompatActivity;
import android.os.Bundle;

import android.graphics.Typeface;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity implements View.OnClickListener {

    private float mTextSize = 20;
    private EditText mEdit;
    private TextView tSize;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mEdit = findViewById(R.id.editText);
        tSize = findViewById(R.id.size);

        Button btnB = findViewById(R.id.btnB);
        Button btnI = findViewById(R.id.btnI);

        Button btnSizeMin = findViewById(R.id.btnSizeMin);
        Button btnSizeMax = findViewById(R.id.btnSizeMax);

        Button btnSans = findViewById(R.id.btnSans);
        Button btnSerif = findViewById(R.id.btnSerif);
        Button btnMono = findViewById(R.id.btnMono);

        Button btnReset = findViewById(R.id.btnReset);

        btnB.setOnClickListener(this);
        btnI.setOnClickListener(this);

        btnSizeMin.setOnClickListener(this);
        btnSizeMax.setOnClickListener(this);

        btnSans.setOnClickListener(this);
        btnSerif.setOnClickListener(this);
        btnMono.setOnClickListener(this);

        btnReset.setOnClickListener(this);
    }

    @Override
    public void onClick(View v) {
        if (v.getId() == R.id.btnSizeMax && mTextSize < 72) {
            mTextSize += 2;
            mEdit.setTextSize(mTextSize);
            tSize.setText(String.format("%.0f", mTextSize));
        } else if (v.getId() == R.id.btnSizeMin && mTextSize > 18) {
            mTextSize -= 2;
            mEdit.setTextSize(mTextSize);
            tSize.setText(String.format("%.0f", mTextSize));
        } else if (v.getId() == R.id.btnB) {
            if (mEdit.getTypeface().getStyle() == Typeface.ITALIC) {
                mEdit.setTypeface(mEdit.getTypeface(),
                        Typeface.BOLD_ITALIC);
            } else if (mEdit.getTypeface().getStyle() ==
                    Typeface.BOLD_ITALIC) {
                mEdit.setTypeface(mEdit.getTypeface(),
                        Typeface.ITALIC);
            } else if (mEdit.getTypeface().getStyle() == Typeface.BOLD) {
                mEdit.setTypeface(Typeface.create(mEdit.getTypeface(),
                        Typeface.NORMAL));
            } else mEdit.setTypeface(mEdit.getTypeface(), Typeface.BOLD);
        } else if (v.getId() == R.id.btnI) {
            if (mEdit.getTypeface().getStyle() == Typeface.BOLD)
                mEdit.setTypeface(mEdit.getTypeface(),
                        Typeface.BOLD_ITALIC);
            else if (mEdit.getTypeface().getStyle() ==
                    Typeface.BOLD_ITALIC)
                mEdit.setTypeface(mEdit.getTypeface(),
                        Typeface.BOLD);
            else if (mEdit.getTypeface().getStyle() == Typeface.ITALIC)
                mEdit.setTypeface(Typeface.create(mEdit.getTypeface(),
                        Typeface.NORMAL));
            else mEdit.setTypeface(mEdit.getTypeface(), Typeface.ITALIC);
        } else if (v.getId() == R.id.btnSans) {
            if (mEdit.getTypeface().getStyle() == Typeface.ITALIC)
                mEdit.setTypeface(Typeface.SANS_SERIF,
                        Typeface.ITALIC);
            else if (mEdit.getTypeface().getStyle() ==
                    Typeface.BOLD_ITALIC)
                mEdit.setTypeface(Typeface.SANS_SERIF,
                        Typeface.BOLD_ITALIC);
            else if (mEdit.getTypeface().getStyle() == Typeface.BOLD)
                mEdit.setTypeface(Typeface.SANS_SERIF, Typeface.BOLD);
            else mEdit.setTypeface(Typeface.SANS_SERIF,
                        Typeface.NORMAL);
        } else if (v.getId() == R.id.btnSerif) {
            if (mEdit.getTypeface().getStyle() == Typeface.ITALIC) {
                mEdit.setTypeface(Typeface.SERIF, Typeface.ITALIC);
            } else if (mEdit.getTypeface().getStyle() ==
                    Typeface.BOLD_ITALIC) {
                mEdit.setTypeface(Typeface.SERIF,
                        Typeface.BOLD_ITALIC);
            } else if (mEdit.getTypeface().getStyle() == Typeface.BOLD) {
                mEdit.setTypeface(Typeface.SERIF, Typeface.BOLD);
            } else mEdit.setTypeface(Typeface.SERIF, Typeface.NORMAL);
        } else if (v.getId() == R.id.btnMono) {
            if (mEdit.getTypeface().getStyle() == Typeface.ITALIC) {
                mEdit.setTypeface(Typeface.MONOSPACE, Typeface.ITALIC);
            } else if (mEdit.getTypeface().getStyle() ==
                    Typeface.BOLD_ITALIC) {
                mEdit.setTypeface(Typeface.MONOSPACE,
                        Typeface.BOLD_ITALIC);
            } else if (mEdit.getTypeface().getStyle() == Typeface.BOLD) {
                mEdit.setTypeface(Typeface.MONOSPACE, Typeface.BOLD);
            } else mEdit.setTypeface(Typeface.MONOSPACE, Typeface.NORMAL);
        } else if (v.getId() == R.id.btnReset) {
            mTextSize = 20;
            tSize.setText(String.format("%.0f", mTextSize));
            mEdit.setTextSize(20);
            mEdit.setTypeface(Typeface.DEFAULT, Typeface.NORMAL);
        }
    }
}