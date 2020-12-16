<?php include('conexao_mysql.php') ?>
<?php include('utils.php') ?>

<?php
function validaCampos() {
  if (!isset($_POST["nome"]) || empty(trim($_POST["nome"]))) throw new Exception("O campo nome é obrigatório");
  if (!isset($_POST["telefone"])) throw new Exception("O campo telefone é obrigatório");
  if (!isset($_POST["email"]) || empty(trim($_POST["email"]))) throw new Exception("O campo email é obrigatório");
  if (!isset($_POST["especialidade"])) throw new Exception("O campo especialidade é obrigatório");
  if (!isset($_POST["medico"])) throw new Exception("O campo médico é obrigatório");
  if (!isset($_POST["dataConsulta"])) throw new Exception("O campo data de consulta é obrigatório");
  if (!isset($_POST["horarioConsulta"])) throw new Exception("O campo horário de consulta é obrigatório");
}

if ($_SERVER["REQUEST_METHOD"] == "POST") {
  try {
    validaCampos();

    $nome = filtraDados($_POST["nome"]);
    $telefone = filtraDados($_POST["telefone"]);
    $email = filtraDados($_POST["email"]);
    $especialidade = filtraDados($_POST["especialidade"]);
    $medico = filtraDados($_POST["medico"]);
    $dataConsulta = filtraDados($_POST["dataConsulta"]);
    $horarioConsulta = filtraDados($_POST["horarioConsulta"]);

    $sql = <<<SQL
      INSERT INTO agenda(data_agendamento, horario, nome, email, telefone, codigo_medico)
      VALUES (?, ?, ?, ?, ?, ?)
    SQL;

    $stmt = $conn->prepare($sql);
    $stmt->bindParam(1, $dataConsulta);
    $stmt->bindParam(2, $horarioConsulta);
    $stmt->bindParam(3, $nome);
    $stmt->bindParam(4, $email);
    $stmt->bindParam(5, $telefone);
    $stmt->bindParam(6, $medico);

    $stmt->execute();

    $response = new Response();
    $response->error = false;
    $response->message = "Agendamento realizado com sucesso !!!";
    $jsonStr = json_encode($response);
    echo $jsonStr;
  } catch (Exception $e) {
    $response = new Response();
    $response->error = true;
    $response->message = $e->getMessage();
    $jsonStr = json_encode($response);
    echo $jsonStr;
  }
}
?>
