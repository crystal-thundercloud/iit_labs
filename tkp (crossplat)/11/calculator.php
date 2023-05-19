<?php
function show() {
    $firstval = empty($_POST['first'])? 0 : $_POST['first'];
    $secondval = empty($_POST['second'])? 0 : $_POST['second'];
    $actionval = $_POST['action'];

    $optarr = ["sum"=>"Сложить","min"=>"Вычесть","umn"=>"Умножить","del"=>"Разделить","stepen"=>"Возвести в степень","proc"=>"Процент от числа","sqrt"=>"Квадратный корень","sin"=>"Синус","cos"=>"Косинус","tan"=>"Тангенс","ctg"=>"Котангенс"];

    // положила выдачу формы в echo, чтобы сохранить значения полей
    // когда при отправке формы выдаётся результат, но все значения сбрасываются, это грустненько
    echo "<form method='post' action='calculator.php'>
        <table border='1' cellspacing='2' cellpadding='2'>
        <tr><td>Первое число: </td><td><input size='14' type='text' name='first' value=$firstval></td></tr>
        <tr><td>Второе число: </td><td><input size='14' type='text' name='second' value=$secondval></td></tr>
        <tr>
            <td><select size='1' name='action' value=$actionval>";
    foreach ($optarr as $key => $value) { // для сохранения выбранной опции
        if ($actionval == $key) echo "<option value=$key selected>$value</option>";
        else echo "<option value=$key>$value</option>";
    }
    echo "</select></td>
            <td><input type='submit' value='Выполнить'></td>
        </tr>";
}

function calc() {
    global $action, $result, $first, $second;
    switch($action) {
        case "sum":
            $result = $first+$second;
            break;
        case "min":
            $result = $first-$second;
            break;
        case "umn":
            $result = $first*$second;
            break;
        case "del":
            if (!$second) {
                exit("Второе число не введено или равно нулю
                <br> <a href=calculator.php>Назад</a>");
            }
            $result = $first / $second;
            break;
        case "stepen":
            $result = pow($first, $second);
            break;
        case "proc":
            $result = $first * $second / 100;
            break;
        case "sqrt":
            $result = sqrt($first);
            break;
        case "sin":
            $result = sin(deg2rad($first));
            break;
        case "cos":
            $result = cos(deg2rad($first));
            break;
        case "tan":
            $result = tan(deg2rad($first));
            break;
        case "ctg":
            $result = 1 / tan(deg2rad($first));
            break;
    }
}

$first = empty($_POST['first'])? 0 : $_POST['first'];
$second = empty($_POST['second'])? 0 : $_POST['second'];
$action = $_POST['action'];

show();
calc();
?>
        <tr>
            <td>Результат:</td>
            <td><div align="center">
                <?php
                echo "$result";
                ?>
            </div></td>
        </tr>
    </table>
</form>
<p>Квадратный корень, синус, косинус, тангенс, котангенс: функция от первого числа (для тригонометрии - в градусах)</p>