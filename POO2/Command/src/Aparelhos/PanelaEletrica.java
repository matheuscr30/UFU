/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aparelhos;

import Memento.PanelaEletricaM;

/**
 *
 * @author msantome
 */
public class PanelaEletrica {
    private boolean status;

    public boolean getStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }
    
    public void ligarPanela(){
        System.out.println("Panela Eletrica Ligada !");
        this.status = true;
    }
    
     public PanelaEletricaM createMemento(){
        return new PanelaEletricaM(status);
    }
    
    public void recoverMemento(PanelaEletricaM panelinha){
        this.status = panelinha.getStatus();
    } 
}
