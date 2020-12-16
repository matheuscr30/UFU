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
    <link href="../css/privado.css" rel="stylesheet">

    <script src="../js/jquery-3.5.1.min.js"></script>
    <script type="text/javascript" src="../js/utils.js"></script>
  </head>

  <body>
    <?php include('../header.php') ?>

    <?php include('nav_privado.php') ?>

    <main>
      <div class="container mt-5">
        <span class="titleRestrito">Área restrita</span>
        <p class="subtitleRestrito">Utilize a barra de navegação acima para navegar entre os conteudos</p>
      </div>
    </main>

    <?php include('../footer.php') ?>

    <script src="../js/bootstrap.bundle.min.js"></script>
  </body>
</html>
