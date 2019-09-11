/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Memento;

/**
 *
 * @author msantome
 */
public class PanelaEletricaM {
    private boolean status;

    public PanelaEletricaM(boolean status) 
    {
        this.status = status;
    }

    public boolean getStatus(){
        return status;
    }

    public void setStatus(boolean status){
        this.status = status;
    }    
}
