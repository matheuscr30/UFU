$(document).ready(function () {
  $('#formEndereco').on('submit', function (e) {
    e.preventDefault();

    let data = {
      cep: $('#cep').val(),
      logradouro: $('#logradouro').val(),
      bairro: $('#bairro').val(),
      cidade: $('#cidade').val(),
      estado: $('#estado').val()
    };

    $.ajax({
        url: '../db/cadastro_endereco.php',
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
