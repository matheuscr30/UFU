/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controller;

import Model.Beam.ClienteModel;
import Model.DAO.ClienteDAO;
import View.ClienteView;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JOptionPane;

/**
 *
 * @author matheus
 */
public class ClienteController {
   
    
    // TROCAR CLIENTEMODEL POR CLIENTEDAO
    
    
    private ClienteView clienteView;
    private ClienteModel clienteModel;

    public ClienteController(ClienteView clienteView, ClienteModel clienteModel) {
        this.clienteView = clienteView;
        this.clienteModel = clienteModel;
    
        this.clienteView.addSalvarListener(new SalvarListener());
    }
    
    class SalvarListener implements ActionListener{

        @Override
        public void actionPerformed(ActionEvent ae) {
            try {
                
                String nome = clienteView.getjTextFieldNome().getText().toString();
                String email =  clienteView.getjTextFieldEmail().getText().toString();
                String telefone = clienteView.getjTextFieldTelefone().getText().toString();
                
                if(nome.isEmpty() || email.isEmpty() || telefone.isEmpty())
                       throw new NullPointerException();
                
                ClienteModel cliente = new ClienteModel();
                cliente.setNome(nome);
                cliente.setEmail(email);
                cliente.setTelefone(telefone);
                
                new ClienteDAO().CadastrarCliente(cliente);
                
            } catch(Exception e){
                System.out.println(e);
                JOptionPane.showMessageDialog(null, "Dados Incorretos", null, JOptionPane.WARNING_MESSAGE);
            }
        }
    
    }
}
