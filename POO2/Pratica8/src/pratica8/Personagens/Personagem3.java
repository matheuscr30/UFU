/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8.Personagens;

import pratica8.AtaqueBehavior.FireAttack;
import pratica8.CorreBehavior.CorreMedio;
import pratica8.CorreBehavior.CorreRapido;
import pratica8.Personagem;
import pratica8.PuloBehavior.PuloBaixo;
import pratica8.PuloBehavior.PuloMedio;

/**
 *
 * @author matheus
 */
public class Personagem3 extends Personagem{
    public Personagem3(){
        setPulo(new PuloBaixo());
        setCorre(new CorreRapido());
        setAtaque(new FireAttack());
    } 
}
