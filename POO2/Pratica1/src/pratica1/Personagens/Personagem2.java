/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica1.Personagens;

import pratica1.AtaqueBehavior.AtaqueForte;
import pratica1.AtaqueBehavior.AtaqueMedio;
import pratica1.CorreBehavior.CorreMedio;
import pratica1.CorreBehavior.CorreRapido;
import pratica1.Personagem;
import pratica1.PuloBehavior.PuloAlto;
import pratica1.PuloBehavior.PuloMedio;

/**
 *
 * @author matheus
 */
public class Personagem2 extends Personagem {
    public Personagem2(){
       setPulo(new PuloAlto());
       setCorre(new CorreRapido());
       setAtaque(new AtaqueMedio());
   } 
}
