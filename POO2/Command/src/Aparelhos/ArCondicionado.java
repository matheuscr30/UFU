/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Aparelhos;

import Memento.ArCondicionadoM;

/**
 *
 * @author msantome
 */
public class ArCondicionado {
    private boolean status;
    private double temperatura;
    
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

    public void ligarAr(){
        System.out.println("Ar Condicionado Ligado !");
        this.status = true;
    }
    
    public void desligarAr(){
        System.out.println("Ar Condicionado Desligado !");
        this.status = false;
    }

    public ArCondicionadoM createMemento(){
        return new ArCondicionadoM(status,temperatura);
    }
    
    public void recoverMemento(ArCondicionadoM arConM){
        System.out.println("Undo : ");
        this.status = arConM.getStatus();
        this.setTemperatura(arConM.getTemperatura());
    }    
}
