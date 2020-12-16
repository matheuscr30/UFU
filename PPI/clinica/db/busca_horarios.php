<?php include('conexao_mysql.php') ?>
<?php include('utils.php') ?>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  try {
    $valid = true;

    if (isset($_POST["dataConsulta"])) $dataConsulta = filtraDados($_POST["dataConsulta"]);
    else throw new Exception("A data da consulta deve ser fornecida");

    if (isset($_POST["codigoMedico"])) $codigoMedico = filtraDados($_POST["codigoMedico"]);
    else throw new Exception("O codigo medico deve ser fornecido");

    $sql = <<<SQL
      SELECT horario FROM agenda
      INNER JOIN medico ON agenda.codigo_medico = medico.codigo
      WHERE medico.codigo = ? AND agenda.data_agendamento = ?
    SQL;

    $stmt = $conn->prepare($sql);
    $stmt->execute([$codigoMedico, $dataConsulta]);

    $horarios = [];
    while ($row = $stmt->fetch()) {
      $horarios[] = htmlspecialchars($row["horario"]);
    }

    if (!$jsonStr = json_encode($horarios))
      throw new Exception("Falha na funcao json_encode do PHP");

    echo $jsonStr;
  } catch (Exception $e) {
    http_response_code(500);
    $msgErro = $e->getMessage();
    echo $msgErro;
  }
}
?>
