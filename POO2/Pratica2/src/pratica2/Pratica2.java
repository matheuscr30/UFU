/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica2;

import java.util.ArrayList;
import pratica2.Inimigos.Inimigo1;
import pratica2.Inimigos.Inimigo2;
import pratica2.Inimigos.Inimigo3;
import pratica2.Personagens.Personagem1;

/**
 *
 * @author matheus
 */
public class Pratica2 {
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Personagem p1 =  new Personagem1();
        Inimigo1 i1 = new Inimigo1(p1);
        Inimigo2 i2 = new Inimigo2(p1);
        Inimigo3 i3 = new Inimigo3(p1);
        
        p1.setCoord_x(2.45);
        p1.setCoord_y(5.65);        
    }
}
