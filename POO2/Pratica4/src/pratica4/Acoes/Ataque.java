/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica4.Acoes;

import pratica4.IDTipos;
import pratica4.Personagem;

/**
 *
 * @author matheus
 */
public abstract class Ataque {
    
    private int dano;
    private IDTipos id;

    public Ataque(IDTipos id, int dano) {
        this.dano = dano;
        this.id = id;
    }
    
    public abstract void atacar(Personagem p);

    public int getDano() {
        return dano;
    }

    public void setDano(int dano) {
        this.dano = dano;
    }

    public IDTipos getId() {
        return id;
    }

    public void setId(IDTipos id) {
        this.id = id;
    }
}
