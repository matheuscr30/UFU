<!doctype html>
<html lang="pt-br">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title>Trabalho 6 - Exercicio 2</title>

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
        <div id="alertMensagem" class="alert fade d-none" role="alert"></div>

        <p class="fs-5">Cadastre um endereço</p>

        <form class="row gx-4 gy-3" id="formEndereco" method="post">
          <div class="col-sm-4">
            <div class="form-floating">
              <input class="form-control" type="text" id="cep" name="cep" placeholder="cep">
              <label for="cep" id="cep">CEP</label>
            </div>
          </div>

          <div class="col-sm-8">
            <div class="form-floating">
              <input class="form-control" type="text" id="logradouro" name="logradouro" placeholder="logradouro">
              <label for="logradouro" id="logradouro">Logradouro</label>
            </div>
          </div>

          <div class="col-12">
            <div class="form-floating">
              <input class="form-control" type="text" id="bairro" name="bairro" placeholder="bairro">
              <label for="bairro" id="bairro">Bairro</label>
            </div>
          </div>

          <div class="col-sm-6">
            <div class="form-floating">
              <input class="form-control" type="text" id="cidade" name="cidade" placeholder="cidade">
              <label for="cidade" id="cidade">Cidade</label>
            </div>
          </div>

          <div class="col-sm-6">
            <div class="form-floating">
              <select class="form-select" id="estado" name="estado" placeholder="estado">
                <option selected>Selecione uma opção</option>
                <option value="MG">MG</option>
                <option value="MG">SP</option>
                <option value="MG">RJ</option>
                <option value="MG">MT</option>
                <option value="MG">MS</option>
              </select>
              <label for="estado" id="estado">Estado</label>
            </div>
          </div>

          <div class="col-12">
            <button type="submit" class="btn btn-success">Cadastrar</button>
          </div>
        </form>
      </main>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.0.0-alpha3/dist/js/bootstrap.bundle.min.js" integrity="sha384-popRpmFF9JQgExhfw5tZT4I9/CI5e2QcuUZPOVXb1m7qUmeR2b50u+YFEYe1wgzy" crossorigin="anonymous"></script>
    <script type="text/javascript">
      function mostraMensagem(error, message) {
        if (error) {
          $('#alertMensagem').addClass('alert-danger');
          $('#alertMensagem').removeClass('alert-success');
        }
        else {
          $('#alertMensagem').removeClass('alert-danger');
          $('#alertMensagem').addClass('alert-success');
        }

        $('#alertMensagem').html(message);
        $('#alertMensagem').removeClass('d-none');
        $('#alertMensagem').addClass('show');
      }

      $(document).ready(function () {
        $('#formEndereco').on('submit', function (e) {
          e.preventDefault();

          let data = {
            cep: $('#cep').val(),
            logradouro: $('#logradouro').val(),
            bairro: $('#bairro').val(),
            cidade: $('#cidade').val(),
            estado: $('#estado').val()
          };

          $.ajax({
              url: 'cadastro_endereco.php',
              type: 'POST',
              async: true,
              dataType: 'json',
              data,
              success: (result) => {
                mostraMensagem(result.error, result.message);
              },
              error: (xhr, textStatus, error) => {
                console.log(xhr, textStatus, error);
              }
          });
        });
      });
    </script>
  </body>
</html>
