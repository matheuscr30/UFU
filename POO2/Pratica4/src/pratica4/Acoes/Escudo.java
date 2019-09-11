/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica4.Acoes;

import pratica4.IDTipos;

/**
 *
 * @author matheus
 */
public abstract class Escudo {
    
    protected Escudo next;
    protected IDTipos tipo;

    public Escudo(IDTipos tipo) {
        this.tipo = tipo;
        next = null;
    }
    
    public void setNext(Escudo escudo){
        if(next == null ){
            next = escudo;
        } else {
            next.setNext(escudo);
        }
    }
    
    public boolean defender(IDTipos id) {
        
        if(podeDefender(id)){
            defesaFeita();
            return true;
        } else {
            if(next == null){
                return false;
            }
            return next.defender(id);
        }
        
    }
    
    public boolean podeDefender(IDTipos id){
        return id == tipo;
    }
    
    public abstract void defesaFeita();
}
