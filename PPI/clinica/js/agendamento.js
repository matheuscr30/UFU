function ativaDataConsulta() {
  $('#data_consulta').prop('disabled', false);
  $('#data_consulta').val('');
  $('#horario_consulta').prop('disabled', true);
  $('#horario_consulta').val('');
}

function buscaMedicos(especialidade) {
    if (!especialidade.length) return;

    $.ajax({
        url: '../db/busca_medicos.php',
        type: 'POST',
        async: true,
        dataType: 'json',
        data: { especialidade },
        success: (result) => {
            if (result != "") {
                parseMedicos(result);
            }
        },
        error: (xhr, textStatus, error) => alert(textStatus + error + xhr.responseText)
    });
}

function parseMedicos(medicos) {
  $('#medico option:not(.default)').remove();

  for (let medico of medicos) {
    $('#medico').append(
      `
        <option class="text-capitalize" value=${medico.codigo}>
          ${medico.nome} - ${medico.crm}
        </option>
      `
    );
  }

  $('#medico').prop('disabled', false);
  $('#data_consulta').val('');
  $('#horario_consulta').prop('disabled', true);
  $('#horario_consulta').val('');
}

function buscaHorarios(dataConsulta) {
  let codigoMedico = $('#medico').val();

  if (!dataConsulta || !codigoMedico) return;

  $.ajax({
      url: '../db/busca_horarios.php',
      type: 'POST',
      async: true,
      dataType: 'json',
      data: { codigoMedico, dataConsulta },
      success: (result) => {
        parseHorarios(result);
      },
      error: (xhr, textStatus, error) => alert(textStatus + error + xhr.responseText)
  });
}

function parseHorarios(horarios) {
  if (horarios && horarios.length) {
    for (let horario of horarios) {
      $(`#horario_consulta option[value="${horario}"]`).prop('disabled', true);
    }
  } else {
    $(`#horario_consulta option:not(.default)`).prop('disabled', false);
  }

  $('#horario_consulta').prop('disabled', false);
  $('#horario_consulta').val('');
}

$(document).ready(function() {
  $('#data_consulta').attr('min', new Date().toISOString().split("T")[0]);

  $('#formAgendamento').on('submit', function(e) {
    e.preventDefault();

    let data = {
      nome: $('#nome').val(),
      telefone: $('#telefone').val(),
      email: $('#email').val(),
      especialidade: $('#especialidade').val(),
      medico: $('#medico').val(),
      dataConsulta: $('#data_consulta').val(),
      horarioConsulta: $('#horario_consulta').val(),
    };

    $.ajax({
        url: '../db/cadastro_agendamento.php',
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

    $('#medico').prop('disabled', true);
    $('#data_consulta').prop('disabled', true);
    $('#horario_consulta').prop('disabled', true);
    $('#formAgendamento')[0].reset();
  });
});
