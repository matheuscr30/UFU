/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ComandoAparelhoForno;

import Aparelhos.Forno;
import com.matheus.Comando;

/**
 *
 * @author msantome
 */
public class ComandoTimer implements Comando{
    private Forno forno;
    private double timer;
    
    public ComandoTimer(Forno forninho){
        this.forno = forninho;
    }
    
    @Override
    public void executar(){
        forno.setTemperatura(timer);
    }
    
    public void setTimer(double timer){
        this.timer = timer;
    }
}