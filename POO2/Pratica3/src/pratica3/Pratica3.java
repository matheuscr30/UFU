/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica3;

import pratica3.Acoes.Ataque;
import pratica3.AtaqueAdicionais.AtaqueFogo;
import pratica3.AtaqueAdicionais.AtaqueGelo;
import pratica3.Personagens.Personagem3;
import pratica3.Personagens.Personagem2;
import pratica3.Personagens.Personagem1;

/**
 *
 * @author matheus
 */
public class Pratica3 {

    /**
     * @param args the command line arguments
     */
    
    //Matheus Cunha Reis - 11521BCC030 
    //Matheus dos Santos Mendes - 11521BCC023
    
    public static void main(String[] args) {
        
        Personagem p1 =  new Personagem1();
        Personagem p2 =  new Personagem2();
        Personagem p3 =  new Personagem3();
        
        System.out.println(p1.atacar());
        Ataque ataque = p1.getAtaque();
        ataque = new AtaqueFogo(ataque);
        ataque = new AtaqueGelo(ataque);
        p1.setAtaque(ataque);
        System.out.println(p1.atacar());
    }
    
}
