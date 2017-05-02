/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculador;

import javax.swing.JFrame;

/**
 *
 * @author matheus
 */
public class Calculador {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        CalculadoraActivity c = new CalculadoraActivity();
        c.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        c.setSize(300,300);
        c.setVisible(true);
    }
    
}
