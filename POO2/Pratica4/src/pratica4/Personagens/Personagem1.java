/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica4.Personagens;

import pratica4.AtaqueBehavior.EarthAttack;
import pratica4.CorreBehavior.CorreMedio;
import pratica4.Personagem;
import pratica4.PuloBehavior.PuloMedio;

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
