/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica4.AtaqueAdicionais;

import pratica4.Acoes.Ataque;
import pratica4.Personagem;

/**
 *
 * @author matheus
 */
public class Ataque3x extends AtaqueDecorator{

    private Ataque ataque;
    
    public Ataque3x(Ataque a) {
        super(a);
        this.ataque = a;
    }

    @Override
    public int getDano() {
        return 3 * ataque.getDano();
    }

    @Override
    public void atacar(Personagem p) {
        ataque.atacar(p);
    }
    
}
