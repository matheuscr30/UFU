/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica2.Personagens;

import pratica2.AtaqueBehavior.AtaqueForte;
import pratica2.CorreBehavior.CorreMedio;
import pratica2.Personagem;
import pratica2.PuloBehavior.PuloMedio;

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
