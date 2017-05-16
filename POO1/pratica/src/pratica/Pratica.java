/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica;

/**
 *
 * @author matheus
 */
public class Pratica {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Pilha pilha = new Pilha(10);
        int nElementos = 10;
        int poping;
        
            for(int i = 0; i<nElementos; i++){
                pilha.push(i+1);
            }
            System.out.println(pilha);
            for(int i = 0; i<nElementos;i++){
                poping = pilha.pop();
                System.out.println("Excluindo elemento " + poping + " da pilha.\n");
            }
            System.out.println(pilha);

    }
    
}
