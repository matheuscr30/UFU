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
public class ComandoDesligarSom implements Comando{
    private AparelhoSom som;
    
    public ComandoDesligarSom(AparelhoSom sonzinho){
        this.som = sonzinho;
    }

    @Override
    public void executar(){
        som.desligarSom();
    }
}