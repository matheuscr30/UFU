/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.matheus;

import java.util.ArrayList;

/**
 *
 * @author msantome
 */
public class ControleRemoto {
    private Comando[] comandoLigado;
    private Comando[] comandoDesligado;
    private Comando tempArCondicionado;
    private Comando tempForno;
    private Comando timer;
    private Comando volume;
    private Comando macroUsuario;
    
    public ControleRemoto(){

        comandoLigado = new Comando[4];
        comandoDesligado = new Comando[4];       
        
        ComandoNenhum nenhum = new ComandoNenhum();
        
        for (int i = 0; i < 4; i++){
            comandoLigado[i] = nenhum;
            comandoDesligado[i] = nenhum;
        }        
    }
    
    public void ComandoMacro(ArrayList<Comando> comandosMacro){
        for (int i = 0; i < comandosMacro.size(); i++)
        {
            comandosMacro.get(i).executar();
        }        
    }
    
    public void setComando(int slot, Comando ligar, Comando desligar){
        this.comandoLigado[slot] = ligar;
        this.comandoDesligado[slot] = desligar;        
    }
    
    public void botaoLigar(int slot){
        comandoLigado[slot].executar();        
    }
    
    public void botaoDesligar(int slot){
        comandoDesligado[slot].executar();        
    }
    
    public void setComandoTempAr(Comando temp){
        this.tempArCondicionado = temp;
    }
    
    public void setComandoTempForno(Comando temp){
        tempForno = temp;
    }
    
    public void setComandoTimer(Comando timer){
        this.timer = timer;
    }
    
    public void setComandoVolume(Comando volume){
        this.volume = volume;
    }
        
    public void executarBotaoTempAr(){
        tempArCondicionado.executar();
    }
    
    public void executarBotaoTempForno(){
        tempForno.executar();
    }
    
    public void executarBotaoTimer(){
        timer.executar();
    }
    
    public void executarBotaoVolume(){
        volume.executar();
    }
    
}
