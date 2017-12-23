/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Caretaker;

import Memento.AparelhoSomM;

/**
 *
 * @author msantome
 */
public class AparelhoSomC {
    private AparelhoSomM somM;

    public AparelhoSomM getMemento(){
        return this.somM;
    }

    public void setMemento(AparelhoSomM somM) 
    {
        this.somM = somM;
    }
}
