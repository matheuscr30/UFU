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
public class OpXOR extends OperadorBinario{
    
    public OpXOR(ExpressaoLogica op1,ExpressaoLogica op2){
        super(op1, op2);
    }

    @Override
    public boolean operacaoLogica() {
        return getOp1().operacaoLogica() ^ getOp2().operacaoLogica();
    }
}