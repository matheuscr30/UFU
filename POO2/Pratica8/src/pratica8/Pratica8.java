/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8;

import pratica8.Acoes.Escudo;
import pratica8.Acoes.Ataque;
import pratica8.AtaqueAdicionais.Ataque2x;
import pratica8.AtaqueBehavior.SnowAttack;
import pratica8.AtaqueBehavior.WindAttack;
import pratica8.Personagens.Personagem1;
import pratica8.TiposEscudos.EarthProtection;
import pratica8.TiposEscudos.WindProtection;

/**
 *
 * @author matheus
 */
public class Pratica8 {

    /**
     * @param args the command line arguments
     */
    
    //Matheus Cunha Reis - 11521BCC030 
    //Matheus dos Santos Mendes - 11521BCC023
    
    public static void main(String[] args) {
        
        Jogo jogo = new FacilJogoFactory();
        jogo.jogar();
    }
}
