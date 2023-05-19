<html>
    <head>
        <title>Календарь</title>
        <style>
            body {
                display: flex;
                width: 100%;
            }

            .flex {
                display: flex;
                max-width: 50%;
                flex-wrap: wrap;
                height: 80%;
            }

            div:not(.flex) {
                margin: 10px;
                padding: 5px;
                border: 1px solid black;
            }

            text {
                color: blueviolet;
                font-size: 20;
                margin: 50px 0 5px 0;
            }

            td.today {
                background-color: darkviolet;
                color: white;
            }

            .weekend {
                color: darkorchid;
            }
        </style>
    </head>

    <body>
        <?php
        $year = date("Y");

        $daysarray = array("","Пн","Вт","Ср","Чт","Пт","Сб","Вс");
        $month = array("1"=>"Январь","2"=>"Февраль","3"=>"Март","4"=>"Апрель","5"=>"Май","6"=>"Июнь","7"=>"Июль","8"=>"Август","9"=>"Сентябрь","10"=>"Октябрь","11"=>"Ноябрь","12"=>"Декабрь");
        
        echo "<div class='flex'>"; 

        for ($k = 1; $k <= 12; $k++) {
            $current = mktime(0, 0, 0, $k, 1, date("Y"));

            $monthdays = date("t", $current);
            $weeks = round($monthdays / 7,0);
            $dayofweek = date("w", $current);
            $dayofmonth = date("j");
            $numberfirstday = date("w", $current);  // если месяц начинается в воскресенье, то число имеет значение 0, что выдаёт неправильный результат
            if ($numberfirstday == 0) $numberfirstday = 7; // поэтому исправляем 0 на 7 и всё работает
        
            echo "<div>";
            echo "<text><b>" . $month[$k] . "(" . $year . ")</b></text><br><br>";
            echo "<table width=\"200\" border=\"0\" cellspacing=\"0\" cellpadding=\"5\">\n\t<tr>\n";

            for ($i = 1; $i <= 7; $i++) {
                if ($i > 5) {
                    echo "\t\t<td><b><font class='weekend'>" . $daysarray[$i] . "</font></b></td>\n";
                } else {
                    echo "\t\t<td>" . $daysarray[$i] . "</td>\n";
                }
            }
            echo "\t</tr>\n\t<tr>\n";

            $j = 1;
            while ($j < $numberfirstday) {
                echo "\t\t<td>&nbsp;</td>\n";
                $j++;
            }

            for ($i = 1; $i <= $monthdays; $i++) {
                if ($i == $dayofmonth && $k == date("m")) {
                    echo "\t\t<td class='today' align=\"center\"><b>" . $i . "</b></td>\n";
                } else {
                    echo "\t\t<td align=\"center\">" . $i . "</td>\n";
                }
                if (round($j / 7) - $j / 7 == 0) {
                    echo "\t</tr>\n\t<tr>\n";
                }
                $j++;
            }
            echo "\t</tr>\n</table>\n";
            echo "</div>";
        }
        echo "</div>";
        ?>
    </body>
</html>