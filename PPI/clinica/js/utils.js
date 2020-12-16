function mostraMensagem(error, message) {
  if (error) {
    $('#alertMensagem').addClass('alert-danger');
    $('#alertMensagem').removeClass('alert-success');
  }
  else {
    $('#alertMensagem').removeClass('alert-danger');
    $('#alertMensagem').addClass('alert-success');
  }

  $('#alertMensagem').html(message);
  $('#alertMensagem').removeClass('d-none');
  $('#alertMensagem').addClass('show');

  setTimeout(() => {
    $('#alertMensagem').addClass('d-none');
  }, 5000);
}
