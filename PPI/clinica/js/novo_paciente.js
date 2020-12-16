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
        url: '../db/cadastro_paciente.php',
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
