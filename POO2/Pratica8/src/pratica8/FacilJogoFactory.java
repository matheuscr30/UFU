/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8;

import java.util.ArrayList;
import pratica8.Acoes.Ataque;
import pratica8.Acoes.Escudo;
import pratica8.Factory.JogoFactory;

/**
 *
 * @author matheus
 */
public class FacilJogoFactory extends Jogo implements JogoFactory {

    @Override
    public void jogar() {
        System.out.println("Iniciando Jogo no Nivel Facil");
        inicializarAtaques();
        inicializarEscudos();
        inicializarInimigos();
    }

    @Override
    public ArrayList<Ataque> inicializarAtaques() {
        ArrayList<Ataque> ataques = new ArrayList<>();
        ataques.add(ataqueFactory.criaAtaque("facil"));
        return ataques;
    }

    @Override
    public ArrayList<Escudo> inicializarEscudos() {
        ArrayList<Escudo> escudos = new ArrayList<>();
        escudos.add(escudoFactory.criaEscudo("facil"));
        return escudos;
    }

    @Override
    public ArrayList<Inimigo> inicializarInimigos() {
        ArrayList<Inimigo> inimigos = new ArrayList<>();
        inimigos.add(inimigoFactory.criaInimigo("facil"));
        return inimigos;
    }
    
}
