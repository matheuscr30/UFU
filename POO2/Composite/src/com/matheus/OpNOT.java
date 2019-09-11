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
public class OpNOT extends OperadorUnario{
    
    public OpNOT(ExpressaoLogica op1){
        super(op1);
    }

    @Override
    public boolean operacaoLogica() {
        return !(getOp1().operacaoLogica());
    }
}