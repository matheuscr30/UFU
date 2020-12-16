<?php
require "conexao_mysql.php";
$conn = mysqlConnect();

function filtraDados($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

function validaCampos() {
  if (!isset($_POST["cep"])) throw new Exception("O campo CEP é obrigatório");
  if (!isset($_POST["logradouro"]) && !empty(trim($_POST["logradouro"]))) throw new Exception("O campo logradouro é obrigatório");
  if (!isset($_POST["bairro"]) && !empty(trim($_POST["bairro"]))) throw new Exception("O campo bairro é obrigatório");
  if (!isset($_POST["cidade"]) && !empty(trim($_POST["cidade"]))) throw new Exception("O campo cidade é obrigatório");
  if (!isset($_POST["estado"]) && !empty(trim($_POST["estado"]))) throw new Exception("O campo estado é obrigatório");
}

class Response {
  public $error;
  public $message;
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
  try {
    validaCampos();

    $cep = filtraDados($_POST["cep"]);
    $logradouro = filtraDados($_POST["logradouro"]);
    $bairro = filtraDados($_POST["bairro"]);
    $cidade = filtraDados($_POST["cidade"]);
    $estado = filtraDados($_POST["estado"]);

    $sql = <<<SQL
      INSERT INTO base_enderecos_ajax(cep, logradouro, bairro, cidade, estado)
      VALUES (?, ?, ?, ?, ?)
    SQL;

    $stmt = $conn->prepare($sql);
    $stmt->bindParam(1, $cep);
    $stmt->bindParam(2, $logradouro);
    $stmt->bindParam(3, $bairro);
    $stmt->bindParam(4, $cidade);
    $stmt->bindParam(5, $estado);

    $stmt->execute();

    $response = new Response();
    $response->error = false;
    $response->message = "Endereço cadastrado com sucesso !!!";
    $jsonStr = json_encode($response);
    echo $jsonStr;
  } catch (PDOException $e) {
    if ($e->errorInfo[1] == 1062) {
      $response = new Response();
      $response->error = true;
      $response->message = "CEP já cadastrado";
      $jsonStr = json_encode($response);
      echo $jsonStr;
    }
  } catch (Exception $e) {
    $response = new Response();
    $response->error = true;
    $response->message = $e->getMessage();
    $jsonStr = json_encode($response);
    echo $jsonStr;
  }
}
?>
