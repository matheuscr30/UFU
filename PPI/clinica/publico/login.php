<?php session_start(); ?>
<?php include('../db/conexao_mysql.php') ?>
<?php include('../db/utils.php') ?>

<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
  $errorMsg = "";
  $hasError = false;

  try {
    if (!isset($_POST["email"]) || empty(trim($_POST["email"]))) throw new Exception("O campo email é obrigatório");
    if (!isset($_POST["senha"]) || empty(trim($_POST["senha"]))) throw new Exception("O campo senha é obrigatório");

    $email = filtraDados($_POST["email"]);
    $senha = filtraDados($_POST["senha"]);

    $sql = <<<SQL
      SELECT senha_hash FROM pessoa INNER JOIN
      funcionario ON pessoa.codigo = funcionario.codigo
      WHERE email = ?
    SQL;

    $stmt = $conn->prepare($sql);
    $stmt->execute([$email]);
    $row = $stmt->fetch();

    if (!$row || !password_verify($senha, $row['senha_hash'])) {
      $hasError = true;
      $errorMsg = "Email e/ou senha inválidos";
    } else {
      $_SESSION["email_usuario_logado"] = $email;
      echo <<<SCRIPT
        <script>window.location.href = "../privado";</script>
      SCRIPT;
    }
  } catch (Exception $e) {
    $hasError = true;
    $errorMsg = $e->getMessage();
  }
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
  </head>

  <body>
    <?php include('../header.php') ?>

    <?php include('nav_publico.php') ?>

    <main>
      <div class="container mt-5">
        <?php
          if (isset($hasError) && $hasError) {
            echo <<<HTML
              <div class="alert alert-danger fade show" role="alert">
                $errorMsg
              </div>
            HTML;
          }
        ?>


        <span class="main-title">Faça o login no sistema</span>

        <form class="row gx-4 gy-3 mt-1" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>" method="post">
          <div class="col-12">
            <div class="form-floating">
              <input class="form-control" type="email" id="email" name="email" placeholder="email" required>
              <label for="email" id="email">Email</label>
            </div>
          </div>

          <div class="col-12">
            <div class="form-floating">
              <input class="form-control" type="password" id="senha" name="senha" placeholder="senha" required>
              <label for="senha" id="senha">Senha</label>
            </div>
          </div>

          <div class="col-12">
            <button type="submit" class="btn btn-register">Logar</button>
          </div>
        </form>
      </div>
    </main>

    <?php include('../footer.php') ?>

    <script src="../js/bootstrap.bundle.min.js"></script>
  </body>
</html>
