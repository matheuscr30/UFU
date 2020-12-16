<?php
function filtraDados($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  return $data;
}

function buscaUsuarioLogado($conn) {
  if(!isset($_SESSION["email_usuario_logado"])) return null;

  $email = htmlspecialchars($_SESSION["email_usuario_logado"]);

  $sql = <<<SQL
    SELECT email FROM pessoa
    INNER JOIN funcionario ON pessoa.codigo = funcionario.codigo
    WHERE pessoa.email = ?
  SQL;

  $stmt = $conn->prepare($sql);
  $stmt->execute([$email]);
  $row = $stmt->fetch();

  if(!$row) return null;

  $usuario = new UsuarioLogado();
  $usuario->email = $row['email'];

  $sql = <<<SQL
    SELECT email FROM pessoa
    INNER JOIN medico ON pessoa.codigo = medico.codigo
    WHERE pessoa.email = ?
  SQL;

  $stmt = $conn->prepare($sql);
  $stmt->execute([$email]);
  $row = $stmt->fetch();

  if($row) {
    $usuario->ehMedico = true;
  } else {
    $usuario->ehMedico = false;
  }

  return $usuario;
}

function alert($message) {
  echo <<<HTML
    <script>alert("$message")</script>
  HTML;
}

class Response {
  public $error;
  public $message;
}

class UsuarioLogado {
  public $email;
  public $ehMedico;
}
?>
