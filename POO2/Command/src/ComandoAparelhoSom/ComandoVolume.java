/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ComandoAparelhoSom;

import Aparelhos.AparelhoSom;
import com.matheus.Comando;

/**
 *
 * @author msantome
 */
public class ComandoVolume implements Comando{
    private AparelhoSom som;
    private int volume;
    
    public ComandoVolume(AparelhoSom sonzinho){
        this.som = sonzinho;
    }
        
    @Override
    public void executar(){
        som.setVolume(volume);
    }
    
    public void setVolume(int vol){
        this.volume = vol;
    }
}