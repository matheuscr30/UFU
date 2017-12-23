/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica7;

/**
 *
 * @author matheus
 */
public class DVDPlayer {
    
    public void ligar(){
        System.out.println("Ligar - DVDPlayer");
    }
    
    public void desligar(){
        System.out.println("Desligar - DVDPlayer");
    }
    
    public void eject(){
        System.out.println("Eject - DVDPlayer");
    }
    
    public void pause(){
        System.out.println("Pause - DVDPlayer");
    }
    
    public void play(Filme filme){
        System.out.println("Play - DVDPlayer");
    }
    
    public void stop(){
        System.out.println("Stop - DVDPlayer");
    }
    
    public void setSurroundAudio(){
        System.out.println("SetSurrondAudio - DVDPlayer");
    }
    
    public void setStereoAudio(){
        System.out.println("SetStereoAudio - DVDPlayer");
    }
}
