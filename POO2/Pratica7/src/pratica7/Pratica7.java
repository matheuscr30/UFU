/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica7;

/**
 *
 * @author matheus
 */
public class Pratica7 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        HomeTheaterFacade htf = new HomeTheaterFacade(new Amplificador(), new Tela(), new Pipoqueira(),
            new LuzAmbiente(), new DVDPlayer(), new CDPlayer(), new Projetor(), new Sintonizador());
        
        Filme filme = new Filme("KINGSMAN", 130);
        htf.assistirFilme(filme);
        htf.pararFilme();
        
        CD cd = new CD("Shakira", 65);
        htf.ouvirCD(cd);
        htf.pararCD();
    }
    
}
