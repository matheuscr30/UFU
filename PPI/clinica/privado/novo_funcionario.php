<?php session_start(); ?>
<?php include('../db/conexao_mysql.php') ?>
<?php include('../db/utils.php') ?>

<?php
$usuarioLogado = buscaUsuarioLogado($conn);
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
    <script type="text/javascript" src="../js/novo_funcionario.js"></script>
  </head>

  <body>
    <?php include('../header.php') ?>

    <?php include('nav_privado.php') ?>

    <main>
      <div class="container mt-5">
        <div id="alertMensagem" class="alert fade d-none" role="alert"></div>

        <span class="main-title">Cadastre um novo funcionário</span>

        <form class="row gx-4 gy-3 mt-1" id="formFuncionario" method="post">
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

          <div class="col-md-6">
            <div class="form-floating">
              <input class="form-control" type="email" id="email" name="email" placeholder="email" required>
              <label for="email" id="email">Email</label>
            </div>
          </div>

          <div class="col-md-6">
            <div class="form-floating">
              <input class="form-control" type="password" id="senha" name="senha" minlength="8" placeholder="senha" required>
              <label for="senha" id="senha">Senha</label>
            </div>
          </div>

          <div class="col-md-4">
            <div class="form-floating">
              <input class="form-control" type="date" id="data_inicio_contrato" name="data_inicio_contrato" placeholder="data_inicio_contrato" required>
              <label for="data_inicio_contrato" id="data_inicio_contrato">Data de inicio do Contrato</label>
            </div>
          </div>

          <div class="col-md-4">
            <div class="form-floating">
              <input class="form-control" type="number" id="salario" name="salario" placeholder="salario" step=".01" required>
              <label for="salario" id="salario">Salario</label>
            </div>
          </div>

          <div class="col-md-4">
            <div class="form-floating">
              <select class="form-select" id="tipo_funcionario" name="tipo_funcionario" placeholder="tipo_funcionario" required>
                <option selected disabled value="">Selecione uma opção</option>
                <option value="funcionario">Funcionário</option>
                <option value="funcionario_medico">Funcionário Medico</option>
              </select>
              <label for="tipo_funcionario" id="tipo_funcionario">Tipo do Funcionário</label>
            </div>
          </div>

          <div id="especialidade-container" class="col-md-6 d-none">
            <div class="form-floating">
              <input class="form-control" type="text" id="especialidade" name="especialidade" maxlength="30" placeholder="especialidade">
              <label for="especialidade" id="especialidade">Especialidade</label>
            </div>
          </div>

          <div id="crm-container" class="col-md-6 d-none">
            <div class="form-floating">
              <input class="form-control" type="text" id="crm" name="crm" maxlength="30" placeholder="crm">
              <label for="crm" id="crm">CRM</label>
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
            <button type="submit" class="btn btn-register">Cadastrar</button>
          </div>
        </form>
      </div>
    </main>

    <?php include('../footer.php') ?>

    <script src="../js/bootstrap.bundle.min.js"></script>
  </body>
</html>
