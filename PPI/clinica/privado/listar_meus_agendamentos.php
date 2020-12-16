<?php session_start(); ?>
<?php include('../db/conexao_mysql.php') ?>
<?php include('../db/utils.php') ?>

<?php
$usuarioLogado = buscaUsuarioLogado($conn);

if (!$usuarioLogado->ehMedico) {
  header("Location: index.php");
  exit();
}

class Agendamento {
  public $dataAgendamento;
  public $horario;
  public $nome;
  public $email;
  public $telefone;
  public $nomeMedico;
}

$agendamentos = [];

$sql = <<<SQL
  SELECT data_agendamento, horario, agenda.nome, agenda.email, agenda.telefone, pessoa.nome as nome_medico
  FROM agenda INNER JOIN pessoa ON agenda.codigo_medico = pessoa.codigo
  WHERE pessoa.email = ?
SQL;

$stmt = $conn->prepare($sql);
$stmt->execute([$usuarioLogado->email]);

while($row = $stmt->fetch()) {
  $agendamento = new Agendamento();
  $agendamento->dataAgendamento = htmlspecialchars($row['data_agendamento']);
  $agendamento->horario = htmlspecialchars($row['horario']);
  $agendamento->nome = htmlspecialchars($row['nome']);
  $agendamento->email = htmlspecialchars($row['email']);
  $agendamento->telefone = htmlspecialchars($row['telefone']);
  $agendamento->nomeMedico = htmlspecialchars($row['nome_medico']);
  $agendamentos[] = $agendamento;
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
        <span class="main-title">Agendamentos</span>

        <div class="table-responsive mt-3">
          <table class="table table-hover">
            <thead>
              <tr>
                <th scope="col">Data</th>
                <th scope="col">Horário</th>
                <th scope="col">Nome</th>
                <th scope="col">Email</th>
                <th scope="col">Telefone</th>
                <th scope="col">Médico</th>
              </tr>
            </thead>
            <tbody>
              <?php
                if (count($agendamentos) === 0) {
                  echo <<<HTML
                    <tr class="text-center">
                      <td colspan="6">
                        <em>Nenhum agendamento encontrado</em>
                      </td>
                    </tr>
                  HTML;
                }

                foreach ($agendamentos as $agendamento) {
                  $timestamp = strtotime($agendamento->dataAgendamento);
                  $dataAgendamento = date("d/m/Y", $timestamp);

                  $timestamp = strtotime($agendamento->horario);
                  $horario = date("H:i", $timestamp);

                  echo <<<HTML
                    <tr>
                      <td>$dataAgendamento</td>
                      <td>$horario</td>
                      <td>$agendamento->nome</td>
                      <td>$agendamento->email</td>
                      <td>$agendamento->telefone</td>
                      <td>$agendamento->nomeMedico</td>
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
