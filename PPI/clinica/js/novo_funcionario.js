function buscaEndereco(cep) {
  if (!cep.length || cep.length !== 10) return;

  $.ajax({
      url: '../db/busca_endereco.php',
      type: 'POST',
      async: true,
      dataType: 'json',
      data: { cep },
      success: (result) => {
          if (result != "") {
              parseEndereco(result);
          }
      },
      error: (xhr, textStatus, error) => alert(textStatus + error + xhr.responseText)
  });
}

function parseEndereco(endereco) {
  if (endereco.logradouro) $('#logradouro').val(endereco.logradouro);
  if (endereco.bairro) $('#bairro').val(endereco.bairro);
  if (endereco.cidade) $('#cidade').val(endereco.cidade);
  if (endereco.estado) $('#estado').val(endereco.estado);
}

$(document).ready(function () {
  $('#tipo_funcionario').on('change', function () {
    let tipoFuncionario = $(this).val();

    if (tipoFuncionario === 'funcionario_medico') {
      $('#especialidade-container').removeClass('d-none');
      $('#crm-container').removeClass('d-none');
    } else {
      $('#especialidade-container').addClass('d-none');
      $('#crm-container').addClass('d-none');
    }
  });

  $('#cep').on('input', function () {
    let cep = $(this).val();
    buscaEndereco(cep);
  });

  $('#formFuncionario').on('submit', function (e) {
    e.preventDefault();

    let data = {
      nome: $('#nome').val(),
      telefone: $('#telefone').val(),
      email: $('#email').val(),
      senha: $('#senha').val(),
      dataInicioContrato: $('#data_inicio_contrato').val(),
      salario: $('#salario').val(),
      cep: $('#cep').val(),
      logradouro: $('#logradouro').val(),
      bairro: $('#bairro').val(),
      cidade: $('#cidade').val(),
      estado: $('#estado').val()
    };

    if ($('#tipo_funcionario').val() === 'funcionario_medico') {
      data.especialidade = $('#especialidade').val();
      data.crm = $('#crm').val();
    }

    $.ajax({
        url: '../db/cadastro_funcionario.php',
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
