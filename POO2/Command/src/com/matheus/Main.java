package com.matheus;
// GRUPO : MATHEUS DOS SANTOS MENDES 
//         MATHEUS CUNHA REIS

import Aparelhos.*;
import Caretaker.*;
import ComandoAparelhoForno.*;
import ComandoAparelhoSom.*;
import ComandoArCondicionado.*;
import ComandoPanelaEletrica.*;
import java.util.ArrayList;

public class Main {
    
    public static void main(String[] args) {
       Forno forno = new Forno();
       AparelhoSom som = new AparelhoSom();
       ArCondicionado arCon = new ArCondicionado();
       PanelaEletrica pan = new PanelaEletrica();
       
       ControleRemoto controle = new ControleRemoto();
       
       ArCondicionadoC arConC = new ArCondicionadoC();
       AparelhoSomC somC = new AparelhoSomC();
       FornoC fornoC = new FornoC();
       PanelaEletricaC panC = new PanelaEletricaC();
       
       ComandoLigarArCon ligaAr = new ComandoLigarArCon(arCon);
       ComandoLigarSom ligaSom = new ComandoLigarSom(som);
       ComandoLigarForno ligaForno = new ComandoLigarForno(forno);
       ComandoLigarPanela ligaPanela = new ComandoLigarPanela(pan);
       
       ComandoDesligarArCon desligaAr = new ComandoDesligarArCon(arCon);
       ComandoDesligarSom desligaSom = new ComandoDesligarSom(som);
       ComandoDesligarForno desligaForno = new ComandoDesligarForno(forno);
       
       ComandoTemperaturaArCon temperaturaAr = new ComandoTemperaturaArCon(arCon);
       ComandoTemperaturaForno temperaturaForno = new ComandoTemperaturaForno(forno);
       
       ComandoVolume volumeSom = new ComandoVolume(som);
       
       ComandoTimer timerForno = new ComandoTimer(forno);
       
       ComandoNenhum nenhum = new ComandoNenhum();
       
        controle.setComando(0, ligaAr, desligaAr);
        controle.setComando(1, ligaSom, desligaSom);
        controle.setComando(2, ligaForno, desligaForno);
        controle.setComando(3, ligaPanela, nenhum);
        controle.setComandoTempAr(temperaturaAr);
        controle.setComandoTempForno(temperaturaForno);
        controle.setComandoTimer(timerForno);
        controle.setComandoVolume(volumeSom);
        
        temperaturaAr.setTemperatura(22);
        controle.botaoLigar(0);
        controle.executarBotaoTempAr();
        arConC.setMemento(arCon.createMemento());
        controle.botaoDesligar(0);        
        
        volumeSom.setVolume(20);
        controle.botaoLigar(1);
        controle.executarBotaoVolume();
        somC.setMemento(som.createMemento());
        controle.botaoDesligar(1); 
        
        temperaturaForno.setTemperatura(200);
        timerForno.setTimer(30);        
        controle.botaoLigar(2);
        controle.executarBotaoTimer();
        controle.executarBotaoTempForno();
        fornoC.setMemento(forno.createMemento());           
        controle.botaoDesligar(2); 
           
        controle.botaoLigar(3);
        panC.setMemento(pan.createMemento());
        System.out.printf("\n");
        
        
        ArrayList <Comando> comandosMacro = new ArrayList<>();
          
        comandosMacro.add(ligaAr);
        comandosMacro.add(temperaturaAr);
        comandosMacro.add(ligaForno);
        comandosMacro.add(temperaturaForno);
        comandosMacro.add(timerForno);
        comandosMacro.add(ligaPanela);
        comandosMacro.add(ligaSom);
        comandosMacro.add(volumeSom);
        controle.ComandoMacro(comandosMacro);   


    }
    
}
