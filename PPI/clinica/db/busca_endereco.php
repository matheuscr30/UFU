<?php include('conexao_mysql.php') ?>
<?php include('utils.php') ?>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  class Endereco {
    public $cep;
    public $logradouro;
    public $bairro;
    public $cidade;
    public $estado;
  }

  try {
    if (isset($_POST["cep"])) $cep = filtraDados($_POST["cep"]);
    else throw new Exception("O CEP deve ser fornecido");

    $sql = <<<SQL
      SELECT * FROM base_enderecos_ajax
      WHERE cep = ?
    SQL;

    $stmt = $conn->prepare($sql);
    $stmt->execute([$cep]);

    $row = $stmt->fetch();
    $endereco = new Endereco();

    if ($row) {
      $endereco->cep = htmlspecialchars($row["cep"]);
      $endereco->logradouro = htmlspecialchars($row["logradouro"]);
      $endereco->bairro = htmlspecialchars($row["bairro"]);
      $endereco->cidade = htmlspecialchars($row["cidade"]);
      $endereco->estado = htmlspecialchars($row["estado"]);  
    }

    if (!$jsonStr = json_encode($endereco))
      throw new Exception("Falha na funcao json_encode do PHP");

    echo $jsonStr;
  } catch (Exception $e) {
    http_response_code(500);
    $msgErro = $e->getMessage();
    echo $msgErro;
  }
}
?>
