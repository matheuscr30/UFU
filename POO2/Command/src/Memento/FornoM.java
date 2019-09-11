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
public class FornoM {
    private double temperatura;
    private int timer;
    private boolean status;
    
    public FornoM(double temp,int timer,boolean status){
        this.temperatura = temp;
        this.timer = timer;
        this.status = status;
    }
    
    public double getTemperatura(){
        return temperatura;
    }

    public void setTemperatura(double temperatura){
        this.temperatura = temperatura;
    }

    public double getTimer(){
        return timer;
    }

    public void setTimer(int timer){
        this.timer = timer;
    }

    public boolean getStatus(){
        return status;
    }

    public void setStatus(boolean status){
        this.status = status;
    }
}
