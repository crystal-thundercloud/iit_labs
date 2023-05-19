<?
$path = GetCWD() . "/loadfiles";
$temp = GetCWD() . "/temp";
if (!file_exists($path) || !file_exists($temp))
    die("<b>Пожалуйста, создайте папки <font color=red>" . $path . "</font> и <font color=red>" . $temp . "</font> и <a href=&#63;> повторите попытку загрузить файл</a>.</b>");

else $file = scandir($temp, 1)[0];

if ($_POST['answer'] == "Нет" || empty($_POST)) {
    if ($_POST['answer'] == "Нет") unlink($temp."/".$file); // удалить временно скопированный файл

    if (empty($_FILES['UserFile']['tmp_name'])) 
        echo "<form method=post enctype=multipart/form-data>
                Выберите файл: <input type=file name=UserFile>
                <input type=submit value=Отправить>
                </form>";
    
    elseif (!is_uploaded_file($_FILES['UserFile']['tmp_name']))
        die("<b><font color=red>Файл не был загружен! Попробуйте <a href=&#63;>повторить попытку</a>!</font></b>");

    else {
        if (file_exists($path."/".$_FILES['UserFile']['name'])) { // если такой файл существует
        copy($_FILES['UserFile']['tmp_name'], $temp . chr(47) . $_FILES['UserFile']['name']); // сохранить временную копию
            echo "Файл с именем ". $_FILES['UserFile']['name'] ." уже существует. Заменить? <br>
            <form method='post'>
                <label><input type='radio' name='answer' value='Да' checked>Да</label>
                <label><input type='radio' name='answer' value='Нет'>Нет</label>
                <input type='submit'>
            </form>";
        }
        else if (@!copy($_FILES['UserFile']['tmp_name'], $path . chr(47) . $_FILES['UserFile']['name']))
            die("<b><font color=red>Файл не был загружен! Попробуйте <a href=&#63;>повторить попытку</a>!</font></b>");

        else 
            echo "<center><b>Файл \"<font color=red>" . $_FILES['UserFile']['name'] . "\"</font> успешно загружен на сервер!</font></b></center>" ."<hr>" .
            "Тип файла: <b>" . $_FILES['UserFile']['type'] . "</b><br>" .
            "Размер файла: <b>" . round($_FILES['UserFile']['size'] / 1024, 2) . " кб.</b>" .
            "<hr><center><a href=&#63;>Загрузить ещё один файл! </a></center>";
    }
}
else if ($_POST['answer'] == "Да") {
    if (@!copy($temp . chr(47) . $file, $path . chr(47) . $file))
        die("<b><font color=red>Файл не был загружен! Попробуйте <a href=&#63;>повторить попытку</a>!</font></b>");

    else {
        echo "<center><b>Файл \"<font color=red>" . $file . "\"</font> успешно загружен на сервер!</font></b></center>" . "<hr>" .
        "Тип файла: <b>" . pathinfo($temp."/".$file)['extension'] . "</b><br>" .
        "Размер файла: <b>" . round(filesize($temp."/".$file) / 1024, 2) . " кб.</b>" .
        "<hr><center><a href=&#63;>Загрузить ещё один файл! </a></center>";

        unlink($temp."/".$file); // удалить временно скопированный файл
    }
}
?>