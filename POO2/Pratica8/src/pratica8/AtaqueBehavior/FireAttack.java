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
public class FireAttack extends Ataque {

    public FireAttack() {
        super(IDTipos.fire, 10);
    }

    @Override
    public void atacar(Personagem p) {
        System.out.println("Fire Attack!!!!");
        p.defender(this);
    }
    
}
