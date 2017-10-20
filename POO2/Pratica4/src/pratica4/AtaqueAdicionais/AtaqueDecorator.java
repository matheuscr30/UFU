/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica4.AtaqueAdicionais;

import pratica4.Acoes.Ataque;
import pratica4.IDTipos;
import pratica4.Personagem;

/**
 *
 * @author matheus
 */
public abstract class AtaqueDecorator extends Ataque{

    public AtaqueDecorator(Ataque a) {
        super(a.getId(), a.getDano());
    }
    
    public abstract int getDano();
}
