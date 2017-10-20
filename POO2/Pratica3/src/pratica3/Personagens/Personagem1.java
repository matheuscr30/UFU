/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica3.Personagens;

import pratica3.AtaqueBehavior.AtaqueForte;
import pratica3.CorreBehavior.CorreMedio;
import pratica3.Personagem;
import pratica3.PuloBehavior.PuloMedio;

/**
 *
 * @author matheus
 */
public class Personagem1 extends Personagem {
    
   public Personagem1(){
       setPulo(new PuloMedio());
       setCorre(new CorreMedio());
       setAtaque(new AtaqueForte());
   } 
}
