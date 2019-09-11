/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica7;

/**
 *
 * @author matheus
 */
public class HomeTheaterFacade {
    private Amplificador amplificador;
    private Tela tela;
    private Pipoqueira pipoqueira;
    private LuzAmbiente luzAmbiente;
    private DVDPlayer dvdPlayer;
    private CDPlayer cdPlayer;
    private Projetor projetor;
    private Sintonizador sintonizador;

    public HomeTheaterFacade(Amplificador amplificador, Tela tela, Pipoqueira pipoqueira, LuzAmbiente luzAmbiente, DVDPlayer dvdPlayer, CDPlayer cdPlayer, Projetor projetor, Sintonizador sintonizador) {
        this.amplificador = amplificador;
        this.tela = tela;
        this.pipoqueira = pipoqueira;
        this.luzAmbiente = luzAmbiente;
        this.dvdPlayer = dvdPlayer;
        this.cdPlayer = cdPlayer;
        this.projetor = projetor;
        this.sintonizador = sintonizador;
    }
    
    public void assistirFilme(Filme filme){
        System.out.println("Iniciando o filme");
        pipoqueira.ligar();
        pipoqueira.cozinhar();
        luzAmbiente.dim();
        tela.descer();
        projetor.ligar();
        projetor.setInput(dvdPlayer);
        projetor.modoWideScreen();
        amplificador.ligar();
        amplificador.setDVD();
        amplificador.setSurroundAudio();
        amplificador.setVolume();
        dvdPlayer.ligar();
        dvdPlayer.play(filme);
        System.out.println("Divirta-se :)");
    }
    
    public void pararFilme(){
        System.out.println("Parando o filme");
        pipoqueira.desligar();
        luzAmbiente.desligar();
        projetor.desligar();
        tela.subir();
        amplificador.desligar();
        dvdPlayer.stop();
        dvdPlayer.eject();
        dvdPlayer.desligar();
        System.out.println("Adeus");
    }
    
    public void ouvirCD(CD cd){
        System.out.println("Iniciando o CD");
        amplificador.ligar();
        amplificador.setCD();
        amplificador.setSurroundAudio();
        amplificador.setVolume();
        cdPlayer.ligar();
        cdPlayer.play(cd);
        System.out.println("Divirta-se :)");
    }
    
    public void pararCD(){
        System.out.println("Parando o CD");
        amplificador.desligar();
        cdPlayer.stop();
        cdPlayer.eject();
        cdPlayer.desligar();
        System.out.println("Adeus");
    }
}
