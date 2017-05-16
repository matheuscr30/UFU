/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica11;

/**
 *
 * @author matheus
 */
public class Pratica11 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Pilha p = new Pilha();
        try{
            p.add(0);
            p.add(1);
            p.add(2);
            p.add(3);
            p.add(4);
            p.add(5);
            p.add(6);
            p.add(7);
            p.add(8);
            p.add(9);
            p.add(10);
        }
        catch(Pilhaexcecao r){
            System.out.println(r.getMessage());
        }
    }
    
}
