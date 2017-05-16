/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package teste;

/**
 *
 * @author matheus
 */
public class Teste {

    /**
     * @param args the command line arguments
     */
    public static void main (String args[]) throws Exception {
    	try {
     	   new A().f(2);
     	   System.out.println("Depois do f no main");
     	}
     	catch (TabajaraException e) {
     		System.out.println(e.mensagem);
     	}
     	finally {
     		System.out.println("Antes do fim do main");
     	}
        System.out.println("Fim");
    } 
    
}
