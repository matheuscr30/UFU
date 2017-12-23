/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package com.matheus;

/**
 *
 * @author a11521BCC023
 */
public class Operando implements ExpressaoLogica {
    private boolean conteudo;
    
    public Operando(boolean cont) {
       this.conteudo = cont;
    }
    
    @Override
    public boolean operacaoLogica(){
       return this.conteudo;
    }
         
}
