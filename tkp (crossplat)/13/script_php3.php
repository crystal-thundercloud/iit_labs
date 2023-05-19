<html>
    <head>
        <?php
        $link = empty($_GET['link'])? 0 : $_GET['link'];
        $titles = ["0"=>"Динамическое формирование страниц","1"=>"Божий Ангел, зимним утром...","2"=>"Silentium!","3"=>"Послушайте!"];

        echo "<title>$titles[$link]</title>";
        ?>
        <style>
            pre {
                font-family: 'Times New Roman', Times, serif;
            }
        </style>
    </head>

    <body bgcolor=silver>
        <?php
        $file = "";
        
        if ($link == 1) $file = "script_php3_inc1.html";
        if ($link == 2) $file = "script_php3_inc2.html";
        if ($link == 3) $file = "script_php3_inc3.html";
        if ($file == "") { 
            ?>
            <h3>Пожалуйста, выберите текст:</h3>
            <a href="script_php3.php?link=1">текст N1</a><br>
            <a href="script_php3.php?link=2">текст N2</a><br>
            <a href="script_php3.php?link=3">текст N3</a>
        <?php
        } else {
            include($file);
            switch ($link) {
                case 1:
                    echo "<a href='script_php3.php?link=2'>Следующее</a><br>";
                    break;
                case 2:
                    echo "<a href='script_php3.php?link=1'>Предыдущее</a><br>
                        <a href='script_php3.php?link=3'>Следующее</a><br>";
                    break;
                case 3:
                    echo "<a href='script_php3.php?link=2'>Предыдущее</a><br>";
                    break;
                default:
                    break;
            }
            echo "<a href='script_php3.php?'>К оглавлению</a>";
        }
        ?>
    </body>
</html>