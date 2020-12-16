<?php include('conexao_mysql.php') ?>
<?php include('utils.php') ?>

<?php
function validaCampos() {
  if (!isset($_POST["nome"]) || empty(trim($_POST["nome"]))) throw new Exception("O campo nome é obrigatório");
  if (!isset($_POST["telefone"])) throw new Exception("O campo telefone é obrigatório");
  if (!isset($_POST["email"]) || empty(trim($_POST["email"]))) throw new Exception("O campo email é obrigatório");
  if (!isset($_POST["senha"]) || empty(trim($_POST["senha"]))) throw new Exception("O campo senha é obrigatório");
  if (!isset($_POST["dataInicioContrato"]) || empty(trim($_POST["dataInicioContrato"]))) throw new Exception("O campo data de inicio do contrato é obrigatório");
  if (!isset($_POST["salario"]) || empty(trim($_POST["salario"]))) throw new Exception("O campo salario é obrigatório");
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
    $senha = filtraDados($_POST["senha"]);
    $dataInicioContrato = filtraDados($_POST["dataInicioContrato"]);
    $salario = filtraDados($_POST["salario"]);
    $cep = filtraDados($_POST["cep"]);
    $logradouro = filtraDados($_POST["logradouro"]);
    $bairro = filtraDados($_POST["bairro"]);
    $cidade = filtraDados($_POST["cidade"]);
    $estado = filtraDados($_POST["estado"]);

    if (isset($_POST["especialidade"]) && !empty(trim($_POST["especialidade"])) && isset($_POST["crm"]) && !empty(trim($_POST["crm"]))) {
      $tipoFuncionario = "funcionario_medico";
      $especialidade = filtraDados($_POST["especialidade"]);
      $crm = filtraDados($_POST["crm"]);
    } else {
      $tipoFuncionario = "funcionario";
    }

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
      INSERT INTO funcionario(data_contrato, salario, senha_hash, codigo)
      VALUES (?, ?, ?, ?)
    SQL;

    $senhaHash = password_hash($senha, PASSWORD_DEFAULT);

    $stmt = $conn->prepare($sql);
    $stmt->bindParam(1, $dataInicioContrato);
    $stmt->bindParam(2, $salario);
    $stmt->bindParam(3, $senhaHash);
    $stmt->bindParam(4, $codigoPessoa);

    if(!$stmt->execute()) throw new Exception("Falha no Cadastro");

    if ($tipoFuncionario === "funcionario_medico") {
      $sql = <<<SQL
        INSERT INTO medico(especialidade, crm, codigo)
        VALUES (?, ?, ?)
      SQL;

      $stmt = $conn->prepare($sql);
      $stmt->bindParam(1, $especialidade);
      $stmt->bindParam(2, $crm);
      $stmt->bindParam(3, $codigoPessoa);

      if(!$stmt->execute()) throw new Exception("Falha no Cadastro");
    }

    $conn->commit();

    $response = new Response();
    $response->error = false;
    $response->message = "Funcionário cadastrado com sucesso !!!";
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
