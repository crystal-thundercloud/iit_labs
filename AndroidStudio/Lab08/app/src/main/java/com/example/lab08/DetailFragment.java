package com.example.lab08;

import android.os.Bundle;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.fragment.app.Fragment;

public class DetailFragment extends Fragment {

    String[] descrs = {
            "В целом героическая, благородная группа, автоботы, как правило, привержены делу мира и" +
                    " чувствуют необходимость защищать другие расы от десептиконов. В результате они" +
                    " обычно являются трансформерами, которые переходят в альтернативные режимы, не" +
                    " ориентированные на боевые действия.",
            "Аэроботы - это первая команда по объединению автоботов /гештальт/специальная команда." +
                    " Они превращаются в летательные аппараты земного типа и являются смертельными" +
                    " врагами стантиконов.",
            "Вдохновленные окаменелостями динозавров, найденными Айронхайдом в вулканических пещерах" +
                    " недалеко от Ковчега, Уилджек и Рэтчет спроектировали и построили новых роботов" +
                    " по своему образу и подобию, назвав их диноботами.",
            "Протектоботы - это команда роботов для экстренных служб, спасателей и правоохранительных" +
                    " органов, занимающихся защитой людей и их домов. Они отреагируют на любую" +
                    " чрезвычайную ситуацию с людьми и помогут всем, чем смогут.",
            "Десептиконы обычно озабочены такими вещами, как завоевание Кибертрона, победа над" +
                    " автоботами, накопление большого количества энергона, разработка мощного оружия" +
                    " и избиение людей. В конечном счете, десептиконы хотят защитить свой родной" +
                    " мир, даже если это происходит за счет других.",
            "Завидуя способам передвижения автоботов, Мегатрон украл различные человеческие" +
                    " транспортные средства и настроил их так, чтобы у него была своя собственная" +
                    " автомобильная команда, Cтантиконы, смертельные враги аэроботов.",
            "Инсектиконы - это группа насекомоподобных десептиконов, которые демонстрируют широкий" +
                    " спектр уникальных способностей, включая поедание как органических, так и" +
                    " неорганических веществ для получения энергии и создание собственных клонов.",
            "Комбатиконы - это подразделение свирепых солдат-десептиконов. Комбатиконы не похожи" +
                    " друг на друга, но всех их роднит между собой мстительность и строптивый нрав," +
                    " чрезмерные даже для десептиконов. Они объединяются, образуя Брутикуса."
    };

    int[] pics = {
            R.drawable.autobots,
            R.drawable.aerialbots,
            R.drawable.dinobots,
            R.drawable.protectobots,
            R.drawable.decepticons,
            R.drawable.stunticons,
            R.drawable.insecticons,
            R.drawable.combaticons
    };

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {
        return inflater.inflate(R.layout.fragment_detail, container, false);
    }
    public void setSelectedItem(String selectedItem) {
        TextView desc = getView().findViewById(R.id.detailsText);
        ImageView photo = getView().findViewById(R.id.photo);

        desc.setText(descrs[Integer.parseInt(selectedItem)]);
        photo.setImageResource(pics[Integer.parseInt(selectedItem)]);
    }
}
