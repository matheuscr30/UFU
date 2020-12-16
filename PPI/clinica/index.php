<!DOCTYPE html>
<html lang="pt-br">
  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta name="description" content="Konig Specialité - Uma cliníca médica especializada em cuidar de você">

    <title>Konig Specialité - Clinica Médica</title>

    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link href="css/fontawesome.css" rel="stylesheet">
    <link href="css/main.css" rel="stylesheet">
    <link href="css/index.css" rel="stylesheet">

    <script src="js/jquery-3.5.1.min.js"></script>
  </head>

  <body>
    <?php include('header.php') ?>

    <nav class="navbar navbar-expand-md navbar-light">
      <div class="container-fluid">
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarToggler" aria-controls="navbarToggler" aria-expanded="false" aria-label="Toggle navigation">
          <i class="fas fa-bars text-white"></i>
        </button>
        <div class="collapse navbar-collapse" id="navbarToggler">
          <ul class="navbar-nav mr-auto mb-2 mb-md-0">
            <li class="nav-item">
              <a class="nav-link active" href="#">Home</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="publico/galeria.php">Galeria</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="publico/novo_endereco.php">Novo Endereço</a>
            </li>
            <li class="nav-item">
              <a class="nav-link" href="publico/agendamento.php">Agendamento</a>
            </li>
            <hr class="nav-divider">
            <li class="nav-item d-md-none">
              <a class="nav-link fw-bold" href="publico/login.php">Login</a>
            </li>
          </ul>

          <div class="d-none d-md-flex">
            <a class="nav-link fw-bold" href="publico/login.php">Login</a>
          </div>
        </div>
      </div>
    </nav>

    <main>
      <div class="parallax parallax-img-1">
        <div class="parallax-container">
          <span class="label">Quem somos?</span>
        </div>
      </div>

      <section class="section">
        <p>
          Somos uma clínica médica popular. Surgimos com o objetivo de proporcionar assistência médica de qualidade para aqueles que não podem pagar por um plano de saúde e não querem depender do Sistema Único de Saúde (SUS).
          Garantimos um atendimento rápido, humano, ético e com uma excelente equipe de profissionais da área da saúde. Aqui, você encontra qualidade, agilidade e simplicidade: a saúde é para todos.
        </p>
      </section>

      <div class="parallax parallax-img-2">
        <div class="parallax-container">
          <span class="label">Nossa missão</span>
        </div>
      </div>

      <section class="section">
        <p>
          Nossa missão é oferecer atendimento ambulatorial especializado de qualidade para nossos clientes.
          Prezamos por um atendimento humanizado e com foco no paciente e procuramos agir com ética e responsabilidade.
          Temos os melhores preços na melhor localização!
        </p>
      </section>

      <div class="parallax parallax-img-3">
        <div class="parallax-container">
          <span class="label">Nossos valores</span>
        </div>
      </div>

      <section class="section last">
        <div class="d-flex justify-content-center">
          <ul class="valores">
            <li>Compromisso com o cliente.</li>
            <li>Ética nos negócios.</li>
            <li>Educação e formação de pessoas.</li>
            <li>Disposição e energia positiva.</li>
            <li>Responsabilidade social.</li>
            <li>Respeito e valorização do ser humano.</li>
            <li>Responsabilidade pelos resultados.</li>
            <li>Transparência.</li>
            <li>Qualidade de produtos e serviços.</li>
          </ul>
        </div>
      </section>
    </main>

    <?php include('footer.php') ?>

    <script src="js/bootstrap.bundle.min.js"></script>
  </body>
</html>
