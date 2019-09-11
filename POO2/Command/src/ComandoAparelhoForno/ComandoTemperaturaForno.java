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
public class ComandoTemperaturaForno implements Comando{
    private Forno forno;
    private double temperatura;
    
    public ComandoTemperaturaForno(Forno forninho){
        this.forno = forninho;
    }
    
    @Override
    public void executar(){
        forno.setTemperatura(temperatura);
    }
    
    public void setTemperatura(double temp){
        this.temperatura = temp;
    }
}
