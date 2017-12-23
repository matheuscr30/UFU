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
public class EarthAttack extends Ataque{

    public EarthAttack() {
        super(IDTipos.earth, 5);
    }

    @Override
    public void atacar(Personagem p) {
        System.out.println("Earth Attack!!!!");
        p.defender(this);
    }
}
