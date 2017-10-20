/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package model.DAO;

import JDBC.ConnectionFactory;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import model.beam.Cliente;

/**
 *
 * @author a11521BCC023
 */
public class ClienteDao {
    private Connection conecta;
    
    public ClienteDao(){
        
        this.conecta = ConnectionFactory.getInstance();
    }
    
    public void CadastrarCliente(Cliente obj){
        try{
            String cmdsql = "insert into cliente (nome,telefone,email) values (?,?,?)";
                    
            PreparedStatement stmt = conecta.prepareStatement(cmdsql);
            stmt.setString(1, obj.getNome());
            stmt.setString(2, obj.getTelefone());
            stmt.setString(3, obj.getEmail());
            
            stmt.execute();
            stmt.close();
        }catch(SQLException erro){
            throw new RuntimeException(erro);
        }
    }
}
