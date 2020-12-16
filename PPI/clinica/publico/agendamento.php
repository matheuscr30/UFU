<?php include('../db/conexao_mysql.php') ?>

<?php
$especialidades = [];

$sql = <<<SQL
  SELECT DISTINCT especialidade FROM pessoa
  INNER JOIN funcionario ON pessoa.codigo = funcionario.codigo
  INNER JOIN medico ON funcionario.codigo = medico.codigo
SQL;

$stmt = $conn->query($sql);

while($row = $stmt->fetch()) {
  $especialidades[] = htmlspecialchars($row['especialidade']);
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
    <script type="text/javascript" src="../js/agendamento.js"></script>
  </head>

  <body>
    <?php include('../header.php') ?>

    <?php include('nav_publico.php') ?>

    <main>
      <div class="container mt-5">
        <div id="alertMensagem" class="alert fade d-none" role="alert"></div>

        <span class="main-title">Agende sua consulta</span>

        <form class="row gx-4 gy-3 mt-1" id="formAgendamento" method="post">
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

          <div class="col-md-6">
            <div class="form-floating">
              <select class="form-select" id="especialidade" name="especialidade" placeholder="especialidade" onchange="buscaMedicos(this.value)" required>
                <option selected disabled value="">Selecione uma opção</option>
                <?php
                  foreach ($especialidades as $esp) {
                    echo <<<HTML
                      <option value="$esp" class="text-capitalize">$esp</option>
                    HTML;
                  }
                ?>
              </select>
              <label for="especialidade" id="especialidade">Especialidade médica</label>
            </div>
          </div>

          <div class="col-md-6">
            <div class="form-floating">
              <select class="form-select" id="medico" name="medico" placeholder="medico" disabled required onchange="ativaDataConsulta()">
                <option class="default" selected disabled>Selecione uma opção</option>
              </select>
              <label for="medico" id="medico">Médicos Especialistas</label>
            </div>
          </div>

          <div class="col-md-6">
            <div class="form-floating">
              <input class="form-control" type="date" id="data_consulta" name="data_consulta" placeholder="data_consulta" oninput="buscaHorarios(this.value)" disabled required>
              <label for="data_consulta" id="data_consulta">Data da Consulta</label>
            </div>
          </div>

          <div class="col-md-6">
            <div class="form-floating">
              <select class="form-select" id="horario_consulta" name="horario_consulta" placeholder="horario_consulta" disabled required>
                <option class="default" selected disabled>Selecione uma opção</option>
                <option value="08:00:00">8:00</option>
                <option value="09:00:00">9:00</option>
                <option value="10:00:00">10:00</option>
                <option value="11:00:00">11:00</option>
                <option value="12:00:00">12:00</option>
                <option value="13:00:00">13:00</option>
                <option value="14:00:00">14:00</option>
                <option value="15:00:00">15:00</option>
                <option value="16:00:00">16:00</option>
                <option value="17:00:00">17:00</option>
              </select>
              <label for="horario_consulta" id="horario_consulta">Horário disponível para consulta</label>
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
