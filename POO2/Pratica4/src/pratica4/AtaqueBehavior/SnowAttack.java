/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica4.AtaqueBehavior;

import pratica4.Acoes.Ataque;
import pratica4.IDTipos;
import pratica4.Personagem;

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
