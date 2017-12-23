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
public class AparelhoSomM {
    private int volume;
    private boolean status;

    public AparelhoSomM(boolean status, int vol){
        this.volume = vol;
        this.status = status;
    }

    public int getVolume() {
        return volume;
    }

    public void setVolume(int volume) {
        this.volume = volume;
    }

    public boolean getStatus() {
        return status;
    }

    public void setStatus(boolean status) {
        this.status = status;
    }
    
    
}
