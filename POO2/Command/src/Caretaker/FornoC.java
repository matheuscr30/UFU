/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Caretaker;

import Memento.FornoM;

/**
 *
 * @author msantome
 */
public class FornoC {
    private FornoM fornoM;

    public FornoM getMemento(){
        return this.fornoM;
    }    
    
    public void setMemento(FornoM fornoM){
       this.fornoM = fornoM;
    }
}
