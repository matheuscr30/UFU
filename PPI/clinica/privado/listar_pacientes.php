<?php session_start(); ?>
<?php include('../db/conexao_mysql.php') ?>
<?php include('../db/utils.php') ?>

<?php
$usuarioLogado = buscaUsuarioLogado($conn);

class Paciente {
  public $nome;
  public $email;
  public $telefone;
  public $peso;
  public $altura;
  public $tipoSanguineo;
  public $cep;
  public $logradouro;
  public $bairro;
  public $cidade;
  public $estado;
}

$pacientes = [];

$sql = <<<SQL
  SELECT nome, email, telefone, cep, logradouro, bairro, cidade, estado, peso, altura, tipo_sanguineo
  FROM pessoa INNER JOIN paciente ON pessoa.codigo = paciente.codigo
SQL;

$stmt = $conn->query($sql);

while($row = $stmt->fetch()) {
  $paciente = new Paciente();
  $paciente->nome = htmlspecialchars($row['nome']);
  $paciente->email = htmlspecialchars($row['email']);
  $paciente->telefone = htmlspecialchars($row['telefone']);
  $paciente->peso = htmlspecialchars($row['peso']);
  $paciente->altura = htmlspecialchars($row['altura']);
  $paciente->tipoSanguineo = htmlspecialchars($row['tipo_sanguineo']);
  $paciente->cep = htmlspecialchars($row['cep']);
  $paciente->logradouro = htmlspecialchars($row['logradouro']);
  $paciente->bairro = htmlspecialchars($row['bairro']);
  $paciente->cidade = htmlspecialchars($row['cidade']);
  $paciente->estado = htmlspecialchars($row['estado']);
  $pacientes[] = $paciente;
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
        <span class="main-title">Pacientes</span>

        <div class="table-responsive mt-3">
          <table class="table table-hover">
            <thead>
              <tr>
                <th scope="col">Nome</th>
                <th scope="col">Email</th>
                <th scope="col">Telefone</th>
                <th scope="col">Peso</th>
                <th scope="col">Altura</th>
                <th scope="col">Tipo Sanguíneo</th>
                <th scope="col">CEP</th>
                <th scope="col">Logradouro</th>
                <th scope="col">Bairro</th>
                <th scope="col">Cidade</th>
                <th scope="col">Estado</th>
              </tr>
            </thead>
            <tbody>
              <?php
                if (count($pacientes) === 0) {
                  echo <<<HTML
                    <tr class="text-center">
                      <td colspan="11">
                        <em>Nenhum paciente encontrado</em>
                      </td>
                    </tr>
                  HTML;
                }

                foreach ($pacientes as $paciente) {
                  echo <<<HTML
                    <tr>
                      <td>$paciente->nome</td>
                      <td>$paciente->email</td>
                      <td>$paciente->telefone</td>
                      <td>$paciente->peso</td>
                      <td>$paciente->altura</td>
                      <td>$paciente->tipoSanguineo</td>
                      <td>$paciente->cep</td>
                      <td>$paciente->logradouro</td>
                      <td>$paciente->bairro</td>
                      <td>$paciente->cidade</td>
                      <td>$paciente->estado</td>
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
