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
public abstract class OperadorBinario implements ExpressaoLogica{
    private ExpressaoLogica op1;
    private ExpressaoLogica op2;

    public OperadorBinario(ExpressaoLogica op1, ExpressaoLogica op2) {
        this.op1 = op1;
        this.op2 = op2;
    }
    
    public ExpressaoLogica getOp1(){
        return this.op1;
    }
    
    public ExpressaoLogica getOp2(){
        return this.op2;
    }
}

