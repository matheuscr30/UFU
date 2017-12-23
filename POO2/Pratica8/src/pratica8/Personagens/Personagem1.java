/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8.Personagens;

import pratica8.AtaqueBehavior.EarthAttack;
import pratica8.CorreBehavior.CorreMedio;
import pratica8.Personagem;
import pratica8.PuloBehavior.PuloMedio;

/**
 *
 * @author matheus
 */
public class Personagem1 extends Personagem {
    
   public Personagem1(){
       setPulo(new PuloMedio());
       setCorre(new CorreMedio());
       setAtaque(new EarthAttack());
   } 
}
