<?php session_start(); ?>
<?php include('../db/conexao_mysql.php') ?>
<?php include('../db/utils.php') ?>

<?php
$usuarioLogado = buscaUsuarioLogado($conn);

class Funcionario {
  public $nome;
  public $email;
  public $telefone;
  public $salario;
  public $dataContrato;
  public $cep;
  public $logradouro;
  public $bairro;
  public $cidade;
  public $estado;
}

$funcionarios = [];

$sql = <<<SQL
  SELECT nome, email, telefone, cep, logradouro, bairro, cidade, estado, data_contrato, salario
  FROM pessoa INNER JOIN funcionario ON pessoa.codigo = funcionario.codigo
SQL;

$stmt = $conn->query($sql);

while($row = $stmt->fetch()) {
  $funcionario = new Funcionario();
  $funcionario->nome = htmlspecialchars($row['nome']);
  $funcionario->email = htmlspecialchars($row['email']);
  $funcionario->telefone = htmlspecialchars($row['telefone']);
  $funcionario->salario = htmlspecialchars($row['salario']);
  $funcionario->dataContrato = htmlspecialchars($row['data_contrato']);
  $funcionario->cep = htmlspecialchars($row['cep']);
  $funcionario->logradouro = htmlspecialchars($row['logradouro']);
  $funcionario->bairro = htmlspecialchars($row['bairro']);
  $funcionario->cidade = htmlspecialchars($row['cidade']);
  $funcionario->estado = htmlspecialchars($row['estado']);
  $funcionarios[] = $funcionario;
}
?>

<!DOCTYPE html>
<html lang="pt-br">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="Konig Specialité - Uma cliníca médica especializada em cuidar de você">

    <title>Konig Specialité - Clinica Médica</title>

    <link href="../css/bootstrap.min.css" rel="stylesheet">
    <link href="../css/fontawesome.css" rel="stylesheet">
    <link href="../css/main.css" rel="stylesheet">

    <script src="../js/jquery-3.5.1.min.js"></script>
    <script type="text/javascript" src="../js/utils.js"></script>
  </head>

  <body>
    <?php include('../header.php') ?>

    <?php include('nav_privado.php') ?>

    <main>
      <div class="container mt-5">
        <span class="main-title">Funcionários</span>

        <div class="table-responsive mt-3">
          <table class="table table-hover">
            <thead>
              <tr>
                <th scope="col">Nome</th>
                <th scope="col">Email</th>
                <th scope="col">Telefone</th>
                <th scope="col">Salario</th>
                <th scope="col">Data do Contrato</th>
                <th scope="col">CEP</th>
                <th scope="col">Logradouro</th>
                <th scope="col">Bairro</th>
                <th scope="col">Cidade</th>
                <th scope="col">Estado</th>
              </tr>
            </thead>
            <tbody>
              <?php
                if (count($funcionarios) === 0) {
                  echo <<<HTML
                    <tr class="text-center">
                      <td colspan="10">
                        <em>Nenhum funcionário encontrado</em>
                      </td>
                    </tr>
                  HTML;
                }

                foreach ($funcionarios as $funcionario) {
                  $timestamp = strtotime($funcionario->dataContrato);
                  $dataContrato = date("d/m/Y", $timestamp);

                  echo <<<HTML
                    <tr>
                      <td>$funcionario->nome</td>
                      <td>$funcionario->email</td>
                      <td>$funcionario->telefone</td>
                      <td>$funcionario->salario</td>
                      <td>$dataContrato</td>
                      <td>$funcionario->cep</td>
                      <td>$funcionario->logradouro</td>
                      <td>$funcionario->bairro</td>
                      <td>$funcionario->cidade</td>
                      <td>$funcionario->estado</td>
                    </tr>
                  HTML;
                }
              ?>
            </tbody>
          </table>
        </div>
      </div>
    </main>

    <?php include('../footer.php') ?>

    <script src="../js/bootstrap.bundle.min.js"></script>
  </body>
</html>
