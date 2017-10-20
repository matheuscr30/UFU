/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica4.Personagens;

import pratica4.AtaqueBehavior.FireAttack;
import pratica4.CorreBehavior.CorreMedio;
import pratica4.CorreBehavior.CorreRapido;
import pratica4.Personagem;
import pratica4.PuloBehavior.PuloBaixo;
import pratica4.PuloBehavior.PuloMedio;

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
