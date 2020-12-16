$(document).ready(function(){
  $('.img-thumb').on('click', function(e) {
    let slideId = $(this).data('slide');
    $('#carouselGaleria').carousel(slideId);
  });
});
