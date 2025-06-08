package com.example.lab05;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import android.view.Menu;
import android.view.MenuItem;
import android.widget.ImageView;
import android.widget.LinearLayout;

import android.content.res.Configuration;
import org.jetbrains.annotations.NotNull;

public class MainActivity extends AppCompatActivity {

    public LinearLayout myLayout;
    int counter = 0;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        myLayout = (LinearLayout)findViewById(R.id.root);
    }
    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.menu, menu);
        return true;
    }
    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        if (item.getItemId() == R.id.red) {
            myLayout.setBackgroundColor(getResources().getColor(R.color.red));
            return true;
        }
        else if (item.getItemId() == R.id.green) {
            myLayout.setBackgroundColor(getResources().getColor(R.color.green));
            return true;
        }
        else if (item.getItemId() ==  R.id.blue) {
            myLayout.setBackgroundColor(getResources().getColor(R.color.blue));
            return true;
        }
        else if (item.getItemId() ==  R.id.exit) {
            finish();
            return true;
        }
        else if (item.getItemId() ==  R.id.pow) {
            ImageView iv = new ImageView(myLayout.getContext());
            iv.setImageResource(R.drawable.pow);
            myLayout.addView(iv);
            counter = (counter < 23)? counter+1 : 20;
            return true;
        }
        else return super.onOptionsItemSelected(item);
    }

    public void onConfigurationChanged(@NotNull Configuration newConfig) {
        super.onConfigurationChanged(newConfig);

        if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE) {
                myLayout.setBackgroundResource(R.drawable.background_land);
        }
        else if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT){
            myLayout.setBackgroundResource(R.drawable.background);
        }
    }
}