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
public class ArCondicionadoM {
    private double temperatura;
    private boolean status;    
    
    public ArCondicionadoM(boolean status, double temperatura){
        this.status = status;
        this.temperatura = temperatura;
    }

    public boolean getStatus(){
        return status;
    }
    
    public double getTemperatura(){
        return temperatura;
    }
}
