/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica3.AtaqueAdicionais;

import pratica3.Acoes.Ataque;

/**
 *
 * @author matheus
 */
public class AtaqueAr extends AtaqueDecorator {

    private Ataque ataque;

    public AtaqueAr(Ataque ataque) {
        this.ataque = ataque;
    }

    @Override
    public String atacar() {
        return ataque.atacar() + " Ar";
    }
}