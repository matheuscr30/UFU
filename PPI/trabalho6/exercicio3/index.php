<?php
require "conexao_mysql.php";
$conn = mysqlConnect();

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

<!doctype html>
<html lang="pt-br">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title>Trabalho 6 - Exercicio 3</title>

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-CuOF+2SnTUfTwSZjCXf01h7uYhfOBuxIhGKPbfEJ3+FqH/s6cIFN9bGr1HmAg4fQ" crossorigin="anonymous">

    <script
      src="https://code.jquery.com/jquery-3.5.1.min.js"
      integrity="sha256-9/aliU8dGd2tb6OSsuzixeV4y/faTqgFtohetphbbj0="
      crossorigin="anonymous"></script>
  </head>
  <body>
    <div class="container">
      <main class="mt-5">
        <p class="fs-5">Endereços</p>

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
      </main>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/js/bootstrap.bundle.min.js" integrity="sha384-popRpmFF9JQgExhfw5tZT4I9/CI5e2QcuUZPOVXb1m7qUmeR2b50u+YFEYe1wgzy" crossorigin="anonymous"></script>
  </body>
</html>
