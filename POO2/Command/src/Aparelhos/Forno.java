/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aparelhos;

import Memento.FornoM;
/**
 *
 * @author msantome
 */
public class Forno {
    private boolean status;
    private double temperatura;
    private int timer;

    public boolean getStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }

    public double getTemperatura() {
        return temperatura;
    }

    public void setTemperatura(double temperatura) {
        this.temperatura = temperatura;
        System.out.println("Temperatura : " + temperatura);
    }

    public int getTimer() {
        return timer;
    }

    public void setTimer(int timer) {
        this.timer = timer;
        System.out.println("Timer : " + timer);
    }
    
    public void ligarForno(){
        System.out.println("Forno Ligado !");
        this.status = true;
    }
    
    public void desligarForno(){
        System.out.println("Forno Desligado !");
        this.status = false;
    }
    
    public FornoM createMemento(){
        return new FornoM(temperatura, timer, status);
    }
    
    public void recoverMemento(FornoM forninho){
        System.out.println("Undo");
        this.status = forninho.getStatus();
        this.setTemperatura(forninho.getTemperatura());
        this.timer = (int) forninho.getTimer();
    } 
    
    
}
