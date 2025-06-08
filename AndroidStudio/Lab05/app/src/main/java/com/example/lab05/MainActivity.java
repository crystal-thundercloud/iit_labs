package com.example.lab05;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;

import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.LinearLayout;
import android.widget.TextView;

import android.content.res.Configuration;
import org.jetbrains.annotations.NotNull;

public class MainActivity extends AppCompatActivity {

    public LinearLayout myLayout;
    public String[] lyrics = {
            "You won't get much closer",
            "Till you sacrifice it all (all)",
            "You won't get to taste it",
            "With your face against the wall (wall wall)",
            "Get up and commit",
            "Show the power trapped within (in in)",
            "Do just what you want to",
            "And now stand up and begin",
            "\nOoo 1, 2, 3, 4 fire's in your eyes",
            "And this chaos, it defies imagination",
            "Ooo 5, 6, 7, minus 9 lives",
            "You've arrived at panic station",
            "\nDoubts will try to break you",
            "Unleash your heart and soul (soul)",
            "Trouble will surround you",
            "Start taking some control-(trol!)",
            "Stand up and deliver",
            "Your wildest fantasy-(sy-sy)",
            "Do what the fuck you want to",
            "There's no one to appease",
            "\nOoo 1, 2, 3, 4 fire's in your eyes",
            "And this chaos, it defies imagination",
            "Ooo 5, 6, 7, minus 9 lives",
            "You've arrived at panic station",
            "\nDoubts will try to break you",
    };

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
        else if (item.getItemId() ==  R.id.nextLine) {
            TextView tv = new TextView(myLayout.getContext());
            tv.setText(lyrics[counter]);
            tv.setTextAppearance(this, R.style.lyrics); // по какой-то причине стиль не задаёт цвет фона
            tv.setBackgroundColor(getColor(R.color.blueTransparent));
            tv.setTextAlignment(View.TEXT_ALIGNMENT_CENTER);
            myLayout.addView(tv);
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