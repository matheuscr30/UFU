<?php include('conexao_mysql.php') ?>
<?php include('utils.php') ?>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  class Medico {
    public $codigo;
    public $nome;
    public $crm;
  }

  try {
    if (isset($_POST["especialidade"])) $especialidade = filtraDados($_POST["especialidade"]);
    else throw new Exception("A especialidade médica deve ser fornecida");

    $sql = <<<SQL
      SELECT medico.codigo AS codigo, nome, crm FROM pessoa
      INNER JOIN funcionario ON pessoa.codigo = funcionario.codigo
      INNER JOIN medico ON funcionario.codigo = medico.codigo
      WHERE especialidade = ?
    SQL;

    $stmt = $conn->prepare($sql);
    $stmt->execute([$especialidade]);

    $medicos = [];
    while ($row = $stmt->fetch()) {
      $medico = new Medico();
      $medico->codigo = htmlspecialchars($row["codigo"]);
      $medico->nome = htmlspecialchars($row["nome"]);
      $medico->crm = htmlspecialchars($row["crm"]);
      $medicos[] = $medico;
    }

    if (!$jsonStr = json_encode($medicos))
      throw new Exception("Falha na funcao json_encode do PHP");

    echo $jsonStr;
  } catch (Exception $e) {
    http_response_code(500);
    $msgErro = $e->getMessage();
    echo $msgErro;
  }
}
?>
