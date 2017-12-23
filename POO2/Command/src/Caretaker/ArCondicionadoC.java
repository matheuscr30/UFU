/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Caretaker;

import Memento.ArCondicionadoM;

/**
 *
 * @author msantome
 */
public class ArCondicionadoC {
    private ArCondicionadoM arConM;

    public ArCondicionadoM getMemento(){
        return this.arConM;
    }    
    
    public void setMemento(ArCondicionadoM arConM){
       this.arConM = arConM;
    }
}
