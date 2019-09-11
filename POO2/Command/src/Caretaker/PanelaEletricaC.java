/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Caretaker;

import Memento.PanelaEletricaM;

/**
 *
 * @author msantome
 */
public class PanelaEletricaC {
    private PanelaEletricaM panM;

    public PanelaEletricaM getMemento(){
        return this.panM;
    }    
    
    public void setMemento(PanelaEletricaM panM){
       this.panM = panM;
    }
}
