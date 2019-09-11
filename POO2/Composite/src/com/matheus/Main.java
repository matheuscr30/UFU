package com.matheus;

/**
 *
 * @author a11521BCC023
 */

/* GRUPO : MATHEUS DOS SANTOS MENDES
           MATHEUS CUNHA REIS
*/
public class Main {

    public static void main(String[] args) {
       ExpressaoLogica e = new OpAND(new OpAND(new Operando(true), new OpXOR(new Operando(false), new Operando(true))), new OpNOT(new Operando(false))); 
       System.out.println("" + e.operacaoLogica());
       
       ExpressaoLogica e1 = new OpNOT(new Operando(true));
       System.out.println("" + e1.operacaoLogica());
    }
    
}
