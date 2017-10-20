/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica3.AtaqueBehavior;

import pratica3.Acoes.Ataque;

/**
 *
 * @author matheus
 */
public class AtaqueFraco extends Ataque {

    private String descricao;
    
    public AtaqueFraco() {
        descricao = "Ataque Fraco com Adicionais:";
    }
    
    @Override
    public String atacar(){
        return descricao;
    }
}
