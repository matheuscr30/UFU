<!doctype html>
<html lang="pt-br">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-CuOF+2SnTUfTwSZjCXf01h7uYhfOBuxIhGKPbfEJ3+FqH/s6cIFN9bGr1HmAg4fQ" crossorigin="anonymous">

    <title>Trabalho 5 - Exercicio 2</title>
  </head>
  <body>
    <div class="container">
      <main class="mt-5">
        <?php
          $produtos = [
            "Playstation",
            "TV",
            "Notebook",
            "Smartphone",
            "Mouse",
            "Teclado",
            "Echo Dot",
            "Caneca",
            "Mousepad",
            "Grampeador"
          ];

          $descricoes = [
            "Videogame de ultima geração",
            "Televisor de 50 polegadas",
            "Notebook MSI GS65",
            "Oneplus 8T Cyberpunk version",
            "Mouse Logitech Master MX2",
            "Teclado Logitech K230",
            "Echo Dot integrado com Alexa",
            "Caneca Inteligente",
            "Mousepad Google Chrome",
            "Grampeador Philco"
          ];

          $qde = $_GET["qde"];
        ?>

        <table class="table table-hover">
          <thead>
            <tr>
              <th scope="col">#</th>
              <th scope="col">Produto</th>
              <th scope="col">Descrição</th>
            </tr>
          </thead>
          <tbody>
            <?php
              $indexes = [];

              $count = 0;
              while ($count < $qde) {
                $num = rand(0, 9);

                if (!in_array($num, $indexes, true)) {
                  $indexes[] = $num;
                  $count++;
                }
              }

              for ($i = 0; $i < $qde; $i++) {
                $index = $indexes[$i];
                echo <<<HTML
                  <tr>
                    <th scope="row">$i</th>
                    <td>$produtos[$index]</td>
                    <td>$descricoes[$index]</td>
                  </tr>
                HTML;
              }
            ?>
          </tbody>
        </table>
      </main>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/js/bootstrap.bundle.min.js" integrity="sha384-popRpmFF9JQgExhfw5tZT4I9/CI5e2QcuUZPOVXb1m7qUmeR2b50u+YFEYe1wgzy" crossorigin="anonymous"></script>
  </body>
</html>
