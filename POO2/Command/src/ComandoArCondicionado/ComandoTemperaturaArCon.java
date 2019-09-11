/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ComandoArCondicionado;

import Aparelhos.ArCondicionado;
import com.matheus.Comando;

/**
 *
 * @author msantome
 */
public class ComandoTemperaturaArCon implements Comando{
    private ArCondicionado arCon;
    private double temperatura;
    
    public ComandoTemperaturaArCon(ArCondicionado arC){
        this.arCon = arC;
    }
        
    @Override
    public void executar(){
        arCon.setTemperatura(temperatura);
    }
    
    public void setTemperatura(double temp){
        this.temperatura = temp;
    }
}
