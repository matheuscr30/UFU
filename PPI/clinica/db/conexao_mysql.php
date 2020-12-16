<?php
$db_host = "fdb30.awardspace.net";
$db_username = "3636871_db";
$db_password = "ppisenha2203";
$db_name = "3636871_db";
$dsn = "mysql:host=$db_host; dbname=$db_name; charset=utf8mb4";

$options = [
  PDO::ATTR_EMULATE_PREPARES => false,
  PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION,
  PDO::ATTR_DEFAULT_FETCH_MODE => PDO::FETCH_ASSOC,
];

try {
  $conn = new PDO($dsn, $db_username, $db_password, $options);
} catch (Exception $e) {
  exit('Falha na conexão com o BD: ' . $e->getMessage());
}
?>
