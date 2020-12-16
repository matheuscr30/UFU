<?php include('conexao_mysql.php') ?>
<?php include('utils.php') ?>

<?php
function validaCampos() {
  if (!isset($_POST["nome"]) || empty(trim($_POST["nome"]))) throw new Exception("O campo nome é obrigatório");
  if (!isset($_POST["telefone"])) throw new Exception("O campo telefone é obrigatório");
  if (!isset($_POST["email"]) || empty(trim($_POST["email"]))) throw new Exception("O campo email é obrigatório");
  if (!isset($_POST["peso"]) || empty(trim($_POST["peso"]))) throw new Exception("O campo peso é obrigatório");
  if (!isset($_POST["altura"]) || empty(trim($_POST["altura"]))) throw new Exception("O campo altura é obrigatório");
  if (!isset($_POST["tipoSanguineo"]) || empty(trim($_POST["tipoSanguineo"]))) throw new Exception("O campo tipo sanguineo é obrigatório");
  if (!isset($_POST["cep"])) throw new Exception("O campo CEP é obrigatório");
  if (!isset($_POST["logradouro"]) || empty(trim($_POST["logradouro"]))) throw new Exception("O campo logradouro é obrigatório");
  if (!isset($_POST["bairro"]) || empty(trim($_POST["bairro"]))) throw new Exception("O campo bairro é obrigatório");
  if (!isset($_POST["cidade"]) || empty(trim($_POST["cidade"]))) throw new Exception("O campo cidade é obrigatório");
  if (!isset($_POST["estado"]) || empty(trim($_POST["estado"]))) throw new Exception("O campo estado é obrigatório");
}

if ($_SERVER['REQUEST_METHOD'] === 'POST') {
  try {
    validaCampos();

    $nome = filtraDados($_POST["nome"]);
    $telefone = filtraDados($_POST["telefone"]);
    $email = filtraDados($_POST["email"]);
    $peso = filtraDados($_POST["peso"]);
    $altura = filtraDados($_POST["altura"]);
    $tipoSanguineo = filtraDados($_POST["tipoSanguineo"]);
    $cep = filtraDados($_POST["cep"]);
    $logradouro = filtraDados($_POST["logradouro"]);
    $bairro = filtraDados($_POST["bairro"]);
    $cidade = filtraDados($_POST["cidade"]);
    $estado = filtraDados($_POST["estado"]);

    $conn->beginTransaction();

    $sql = <<<SQL
      INSERT INTO pessoa(nome, email, telefone, cep, logradouro, bairro, cidade, estado)
      VALUES (?, ?, ?, ?, ?, ?, ?, ?)
    SQL;

    $stmt = $conn->prepare($sql);
    $stmt->bindParam(1, $nome);
    $stmt->bindParam(2, $email);
    $stmt->bindParam(3, $telefone);
    $stmt->bindParam(4, $cep);
    $stmt->bindParam(5, $logradouro);
    $stmt->bindParam(6, $bairro);
    $stmt->bindParam(7, $cidade);
    $stmt->bindParam(8, $estado);

    if(!$stmt->execute()) throw new Exception("Falha no Cadastro");
    $codigoPessoa = $conn->lastInsertId();

    $sql = <<<SQL
      INSERT INTO paciente(peso, altura, tipo_sanguineo, codigo)
      VALUES (?, ?, ?, ?)
    SQL;

    $stmt = $conn->prepare($sql);
    $stmt->bindParam(1, $peso);
    $stmt->bindParam(2, $altura);
    $stmt->bindParam(3, $tipoSanguineo);
    $stmt->bindParam(4, $codigoPessoa);

    if(!$stmt->execute()) throw new Exception("Falha no Cadastro");

    $conn->commit();

    $response = new Response();
    $response->error = false;
    $response->message = "Paciente cadastrado com sucesso !!!";
    $jsonStr = json_encode($response);
    echo $jsonStr;
  } catch (PDOException $e) {
    $conn->rollBack();
    if ($e->errorInfo[1] == 1062) {
      $response = new Response();
      $response->error = true;
      $response->message = "Email já cadastrado";
      $jsonStr = json_encode($response);
      echo $jsonStr;
    }
  } catch (Exception $e) {
    $conn->rollBack();
    $response = new Response();
    $response->error = true;
    $response->message = $e->getMessage();
    $jsonStr = json_encode($response);
    echo $jsonStr;
  }
}
?>
