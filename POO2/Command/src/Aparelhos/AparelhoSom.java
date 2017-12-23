/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aparelhos;

import Memento.AparelhoSomM;

/**
 *
 * @author msantome
 */
public class AparelhoSom {
    private boolean status;
    private int volume;
    
    public boolean getStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }
    
    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        this.volume = volume;
        System.out.println("Volume : " + volume);
    }
    
    public void ligarSom(){
        System.out.println("Aparelho de Som Ligado !");
        this.status = true;
    }
    
    public void desligarSom(){
        System.out.println("Aparelho de Som Desligado !");
        this.status = false;
    }

    public AparelhoSomM createMemento(){
        return new AparelhoSomM(status, volume);
    }
    
    public void recoverMemento(AparelhoSomM som){
        System.out.println("Undo");
        this.status = som.getStatus();
        this.setVolume(som.getVolume());
    } 
   
}
