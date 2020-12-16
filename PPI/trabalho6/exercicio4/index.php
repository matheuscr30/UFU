<!doctype html>
<html lang="pt-br">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title>Trabalho 6 - Exercicio 4</title>

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

        <p class="fs-5">Cadastre um paciente</p>

        <form class="row gx-4 gy-3 mt-1" id="formPaciente" method="post">
          <div class="col-md-6">
            <div class="form-floating">
              <input class="form-control" type="text" id="nome" name="nome" placeholder="nome" required>
              <label for="nome" id="nome">Nome</label>
            </div>
          </div>

          <div class="col-md-6">
            <div class="form-floating">
              <input class="form-control" type="text" id="telefone" name="telefone" maxlength="11" placeholder="telefone" required>
              <small class="text-muted ml-1 mt-1">Formato: DDXXXXXXXXX</small>
              <label for="telefone" id="telefone">Telefone</label>
            </div>
          </div>

          <div class="col-12">
            <div class="form-floating">
              <input class="form-control" type="email" id="email" name="email" placeholder="email" required>
              <label for="email" id="email">Email</label>
            </div>
          </div>

          <div class="col-sm-6 col-md-4">
            <div class="form-floating">
              <input class="form-control" type="number" id="peso" name="peso" placeholder="peso" step=".01" required>
              <small class="text-muted ml-1 mt-1">Peso em Kg</small>
              <label for="peso" id="peso">Peso</label>
            </div>
          </div>

          <div class="col-sm-6 col-md-4">
            <div class="form-floating">
              <input class="form-control" type="number" id="altura" name="altura" placeholder="altura" required>
              <small class="text-muted ml-1 mt-1">Altura em Cm</small>
              <label for="altura" id="altura">Altura</label>
            </div>
          </div>

          <div class="col-md-4">
            <div class="form-floating">
              <select class="form-select" id="tipo_sanguineo" name="tipo_sanguineo" placeholder="tipo_sanguineo" required>
                <option selected disabled value="">Selecione uma opção</option>
                <option value="A+">A+</option>
                <option value="A-">A-</option>
                <option value="B+">B+</option>
                <option value="B-">B-</option>
                <option value="AB+">AB+</option>
                <option value="AB-">AB-</option>
                <option value="O+">O+</option>
                <option value="O-">O-</option>
              </select>
              <label for="tipo_sanguineo" id="tipo_sanguineo">Tipo Sanguíneo</label>
            </div>
          </div>

          <div class="col-sm-4">
            <div class="form-floating">
              <input class="form-control" type="text" id="cep" name="cep" placeholder="cep" maxlength="10" pattern="\d{2}\.\d{3}-\d{3}" required>
              <small class="text-muted ml-1 mt-1">Formato: XX.XXX-XXX</small>
              <label for="cep" id="cep">CEP</label>
            </div>
          </div>

          <div class="col-sm-8">
            <div class="form-floating">
              <input class="form-control" type="text" id="logradouro" name="logradouro" maxlength="50" placeholder="logradouro" required>
              <label for="logradouro" id="logradouro">Logradouro</label>
            </div>
          </div>

          <div class="col-12 col-lg-4">
            <div class="form-floating">
              <input class="form-control" type="text" id="bairro" name="bairro" maxlength="50" placeholder="bairro" required>
              <label for="bairro" id="bairro">Bairro</label>
            </div>
          </div>

          <div class="col-sm-6 col-lg-4">
            <div class="form-floating">
              <input class="form-control" type="text" id="cidade" name="cidade" maxlength="50" placeholder="cidade" required>
              <label for="cidade" id="cidade">Cidade</label>
            </div>
          </div>

          <div class="col-sm-6 col-lg-4">
            <div class="form-floating">
              <input class="form-control" type="text" id="estado" name="estado" maxlength="2" placeholder="estado" required>
              <small class="text-muted ml-1 mt-1">Formato: XX</small>
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
        $('#formPaciente').on('submit', function (e) {
          e.preventDefault();

          let data = {
            nome: $('#nome').val(),
            telefone: $('#telefone').val(),
            email: $('#email').val(),
            peso: $('#peso').val(),
            altura: $('#altura').val(),
            tipoSanguineo: $('#tipo_sanguineo').val(),
            cep: $('#cep').val(),
            logradouro: $('#logradouro').val(),
            bairro: $('#bairro').val(),
            cidade: $('#cidade').val(),
            estado: $('#estado').val()
          };

          $.ajax({
              url: 'cadastro_paciente.php',
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
