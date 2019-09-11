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
public class DificilJogoFactory extends Jogo implements JogoFactory{
    
    @Override
    public void jogar() {
        System.out.println("Iniciando Jogo no Nivel Dificil");
    }

    @Override
    public ArrayList<Ataque> inicializarAtaques() {
        ArrayList<Ataque> ataques = new ArrayList<>();
        ataques.add(ataqueFactory.criaAtaque("dificil"));
        return ataques;
    }

    @Override
    public ArrayList<Escudo> inicializarEscudos() {
        ArrayList<Escudo> escudos = new ArrayList<>();
        escudos.add(escudoFactory.criaEscudo("dificil"));
        return escudos;
    }

    @Override
    public ArrayList<Inimigo> inicializarInimigos() {
        ArrayList<Inimigo> inimigos = new ArrayList<>();
        inimigos.add(inimigoFactory.criaInimigo("dificil"));
        return inimigos;
    }
    
}
