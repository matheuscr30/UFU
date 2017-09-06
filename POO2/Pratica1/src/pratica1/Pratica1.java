/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica1;

import pratica1.Personagens.Personagem3;
import pratica1.Personagens.Personagem2;
import pratica1.Personagens.Personagem1;

/**
 *
 * @author matheus
 */
public class Pratica1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Personagem p1 =  new Personagem1();
        Personagem p2 =  new Personagem2();
        Personagem p3 =  new Personagem3();
        
        System.out.println("\nPersonagem 1");
        p1.atacar();
        p1.corre();
        p1.pular();
    
        System.out.println("\nPersonagem 2");
        p2.atacar();
        p2.corre();
        p2.pular();
        
        System.out.println("\nPersonagem 3");
        p3.atacar();
        p3.corre();
        p3.pular();
    }
    
}
