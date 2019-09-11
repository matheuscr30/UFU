/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica5;

import Controller.ClienteController;
import Model.Beam.ClienteModel;
import View.ClienteView;

/**
 *
 * @author matheus
 */
public class Pratica5 {

    //Matheus Cunha Reis - 11521BCC030
    //Matheus dos Santos Mendes - 11521BCC023
    
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ClienteView clienteView = new ClienteView();
        ClienteModel clienteModel = new ClienteModel();
        ClienteController clienteController = new ClienteController(clienteView, clienteModel);
        
        clienteView.setLocationRelativeTo(null);
        clienteView.setVisible(true);
    }
    
}
