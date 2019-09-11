/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8.AtaqueBehavior;

import pratica8.Acoes.Ataque;
import pratica8.IDTipos;
import pratica8.Personagem;

/**
 *
 * @author matheus
 */
public class SnowAttack extends Ataque{

    public SnowAttack() {
        super(IDTipos.snow, 15);
    }

    @Override
    public void atacar(Personagem p) {
        System.out.println("Snow Attack!!!!");
        p.defender(this);
    }
    
}
