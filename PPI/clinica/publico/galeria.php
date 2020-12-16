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
    <link href="../css/galeria.css" rel="stylesheet">

    <script src="../js/jquery-3.5.1.min.js"></script>
    <script src="../js/galeria.js" type="text/javascript"></script>
  </head>

  <body>
    <?php include('../header.php') ?>

    <?php include('nav_publico.php') ?>

    <main>
      <section>
        <h2 class="main-title">Galeria</h2>

        <div id="carouselGaleria" class="carousel slide" data-ride="carousel">
          <ol class="carousel-indicators">
            <li data-target="#carouselGaleria" data-slide-to="0" class="active"></li>
            <li data-target="#carouselGaleria" data-slide-to="1"></li>
            <li data-target="#carouselGaleria" data-slide-to="2"></li>
            <li data-target="#carouselGaleria" data-slide-to="3"></li>
            <li data-target="#carouselGaleria" data-slide-to="4"></li>
            <li data-target="#carouselGaleria" data-slide-to="5"></li>
            <li data-target="#carouselGaleria" data-slide-to="6"></li>
            <li data-target="#carouselGaleria" data-slide-to="7"></li>
          </ol>
          <div class="carousel-inner">
            <div class="carousel-item active">
              <img src="../images/clinica8.jpg">
            </div>
            <div class="carousel-item">
              <img src="../images/clinica9.jpg">
            </div>
            <div class="carousel-item">
              <img src="../images/clinica10.jpg">
            </div>
            <div class="carousel-item">
              <img src="../images/clinica11.jpg">
            </div>
            <div class="carousel-item">
              <img src="../images/clinica12.jpg">
            </div>
            <div class="carousel-item">
              <img src="../images/clinica13.jpg">
            </div>
            <div class="carousel-item">
              <img src="../images/clinica14.jpg">
            </div>
            <div class="carousel-item">
              <img src="../images/clinica15.jpg">
            </div>
          </div>
          <a class="carousel-control-prev" href="#carouselGaleria" role="button" data-slide="prev">
            <span class="carousel-control-prev-icon" aria-hidden="true"></span>
            <span class="visually-hidden">Previous</span>
          </a>
          <a class="carousel-control-next" href="#carouselGaleria" role="button" data-slide="next">
            <span class="carousel-control-next-icon" aria-hidden="true"></span>
            <span class="visually-hidden">Next</span>
          </a>
        </div>

        <div class="row mt-1 thumbs">
          <div class="col p-0 pr-1">
            <img src="../images/clinica8.jpg" class="img-thumb" data-slide="0">
          </div>

          <div class="col p-0 pr-1">
            <img src="../images/clinica9.jpg" class="img-thumb" data-slide="1">
          </div>

          <div class="col p-0 pr-1">
            <img src="../images/clinica10.jpg" class="img-thumb" data-slide="2">
          </div>

          <div class="col p-0">
            <img src="../images/clinica11.jpg" class="img-thumb" data-slide="3">
          </div>
        </div>

        <div class="row mt-1 thumbs">
          <div class="col p-0 pr-1">
            <img src="../images/clinica12.jpg" class="img-thumb" data-slide="4">
          </div>

          <div class="col p-0 pr-1">
            <img src="../images/clinica13.jpg" class="img-thumb" data-slide="5">
          </div>

          <div class="col p-0 pr-1">
            <img src="../images/clinica14.jpg" class="img-thumb" data-slide="6">
          </div>

          <div class="col p-0">
            <img src="../images/clinica15.jpg" class="img-thumb" data-slide="7">
          </div>
        </div>
      </section>
    </main>

    <?php include('../footer.php') ?>

    <script src="../js/bootstrap.bundle.min.js"></script>
  </body>
</html>
