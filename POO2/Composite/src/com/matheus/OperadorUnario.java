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
public abstract class OperadorUnario implements ExpressaoLogica{
    private ExpressaoLogica op1;

    public OperadorUnario(ExpressaoLogica op1) {
        this.op1 = op1;
    }
    
    public ExpressaoLogica getOp1(){
        return this.op1;
    }
    
}

