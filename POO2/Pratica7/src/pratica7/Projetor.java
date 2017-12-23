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
public class Projetor {
    
    public void ligar(){
        System.out.println("Ligar - Projetor");
    }
    
    public void desligar(){
        System.out.println("Desligar - Projetor");
    }
    
    public void modoTv(){
        System.out.println("ModoTV - Projetor");
    }
    
    public void modoWideScreen(){
        System.out.println("ModoWideScreen - Projetor");
    }

    public void setInput(DVDPlayer dvdPlayer) {
        System.out.println("Set Input - Projetor");
    }
}
