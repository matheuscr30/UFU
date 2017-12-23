/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8;

import pratica8.Acoes.Ataque;

/**
 *
 * @author matheus
 */
public class Inimigo {
    
    private Ataque ataque;
    
    public Inimigo(Ataque ataque){
        this.ataque = ataque;
    }
    
    public void atacar(Personagem p){
        p.defender(ataque);
    }

    public Ataque getAtaque() {
        return ataque;
    }

    public void setAtaque(Ataque ataque) {
        this.ataque = ataque;
    }
}
