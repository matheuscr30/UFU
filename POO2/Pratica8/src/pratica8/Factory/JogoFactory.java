/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8.Factory;

import java.util.ArrayList;
import pratica8.Acoes.Ataque;
import pratica8.Acoes.Escudo;
import pratica8.Inimigo;

/**
 *
 * @author matheus
 */
public interface JogoFactory {
    public ArrayList<Ataque> inicializarAtaques();
    public ArrayList<Escudo> inicializarEscudos();
    public ArrayList<Inimigo> inicializarInimigos();
}
