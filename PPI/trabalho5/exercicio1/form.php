<!doctype html>
<html lang="pt-br">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-CuOF+2SnTUfTwSZjCXf01h7uYhfOBuxIhGKPbfEJ3+FqH/s6cIFN9bGr1HmAg4fQ" crossorigin="anonymous">

    <title>Trabalho 5 - Exercicio 1</title>
  </head>
  <body>
    <div class="container">
      <main class="mt-5">
        <div class="row">
          <?php
            $cep = $_POST["cep"];
            $logradouro = $_POST["logradouro"];
            $bairro = $_POST["bairro"];
            $cidade = $_POST["cidade"];
            $estado = $_POST["estado"];

            echo <<<HTML
              <div class="border border-2 col-12 col-sm">CEP: cep</div>
              <div class="border border-2 col-12 col-sm">Logradouro: $logradouro</div>
              <div class="border border-2 col-12 col-sm">Bairro: $bairro</div>
              <div class="border border-2 col-12 col-sm">Cidade: $cidade</div>
              <div class="border border-2 col-12 col-sm">Estado: $estado</div>
            HTML;
          ?>
        </div>
      </main>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/js/bootstrap.bundle.min.js" integrity="sha384-popRpmFF9JQgExhfw5tZT4I9/CI5e2QcuUZPOVXb1m7qUmeR2b50u+YFEYe1wgzy" crossorigin="anonymous"></script>
  </body>
</html>
