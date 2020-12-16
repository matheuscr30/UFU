<?php session_start(); ?>
<?php include('../db/conexao_mysql.php') ?>
<?php include('../db/utils.php') ?>

<?php
$usuarioLogado = buscaUsuarioLogado($conn);

class Endereco {
  public $cep;
  public $logradouro;
  public $bairro;
  public $cidade;
  public $estado;
}

$enderecos = [];

$sql = <<<SQL
  SELECT * FROM base_enderecos_ajax
SQL;

$stmt = $conn->query($sql);

while($row = $stmt->fetch()) {
  $endereco = new Endereco();
  $endereco->cep = htmlspecialchars($row['cep']);
  $endereco->logradouro = htmlspecialchars($row['logradouro']);
  $endereco->bairro = htmlspecialchars($row['bairro']);
  $endereco->cidade = htmlspecialchars($row['cidade']);
  $endereco->estado = htmlspecialchars($row['estado']);
  $enderecos[] = $endereco;
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
        <span class="main-title">Endereços</span>

        <div class="table-responsive mt-3">
          <table class="table table-hover">
            <thead>
              <tr>
                <th scope="col">CEP</th>
                <th scope="col">Logradouro</th>
                <th scope="col">Bairro</th>
                <th scope="col">Cidade</th>
                <th scope="col">Estado</th>
              </tr>
            </thead>
            <tbody>
              <?php
                if (count($enderecos) === 0) {
                  echo <<<HTML
                    <tr class="text-center">
                      <td colspan="5">
                        <em>Nenhum endereço encontrado</em>
                      </td>
                    </tr>
                  HTML;
                }

                foreach ($enderecos as $endereco) {
                  echo <<<HTML
                    <tr>
                      <td>$endereco->cep</td>
                      <td>$endereco->logradouro</td>
                      <td>$endereco->bairro</td>
                      <td>$endereco->cidade</td>
                      <td>$endereco->estado</td>
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
