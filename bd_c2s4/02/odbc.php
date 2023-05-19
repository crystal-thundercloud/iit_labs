<?php
    $host = 'localhost';
    $db = 'shemarevaam';
    $dbuser = 'root';
    $dbpass = 'root';

    $conn = odbc_connect("Driver={MySQL ODBC 8.0 Unicode Driver};Server=$host;Database=$db;", $dbuser, $dbpass);

    if ($conn) echo "\nСоединение установлено\n";
    else echo "Соединение не установлено";

    $sql = "SELECT * FROM petz";

    $res = odbc_exec($conn, $sql);

    while ($row = odbc_fetch_array($res)) {
        echo $row["idpet"]." ".$row["pet_type"]." ".$row["pet_name"]." ".$row["pet_age"]."\n";
    }
?>
