<nav class="navbar navbar-expand-xl navbar-light">
  <div class="container-fluid">
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarToggler" aria-controls="navbarToggler" aria-expanded="false" aria-label="Toggle navigation">
      <i class="fas fa-bars text-white"></i>
    </button>
    <div class="collapse navbar-collapse" id="navbarToggler">
      <ul class="navbar-nav mr-auto mb-2 mb-md-0">
        <li class="nav-item">
          <a class="nav-link" href="novo_funcionario.php">Novo Funcionário</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="novo_paciente.php">Novo Paciente</a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="listar_funcionarios.php">Funcionários</a>
        </li>
        <li class="nav-item">
          <a class="nav-link active" href="listar_pacientes.php">Pacientes</a>
        </li>
        <li class="nav-item">
          <a class="nav-link active" href="listar_enderecos.php">Endereços</a>
        </li>
        <li class="nav-item">
          <a class="nav-link active" href="listar_todos_agendamentos.php">Todos Agendamentos</a>
        </li>
        <hr class="nav-divider">
        <?php
          if ($usuarioLogado && $usuarioLogado->ehMedico) {
            echo <<<HTML
              <li class="nav-item d-xl-none">
                <a class="nav-link fw-bold" href="listar_meus_agendamentos.php">Meus Agendamentos</a>
              </li>
            HTML;
          }
        ?>
        <li class="nav-item d-xl-none">
          <a class="nav-link fw-bold" href="logout.php">Sair</a>
        </li>
      </ul>

      <div class="d-none d-xl-flex">
        <?php
          if ($usuarioLogado && $usuarioLogado->ehMedico) {
            echo <<<HTML
              <a class="nav-link fw-bold" href="listar_meus_agendamentos.php">Meus Agendamentos</a><br>
            HTML;
          }
        ?>
        <a class="nav-link fw-bold" href="logout.php">Sair</a>
      </div>
    </div>
  </div>
</nav>
