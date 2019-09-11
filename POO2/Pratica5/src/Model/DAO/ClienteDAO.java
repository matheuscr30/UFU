/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Model.DAO;

import JDBC.ConnectionFactory;
import Model.Beam.ClienteModel;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;

/**
 *
 * @author matheus
 */
public class ClienteDAO {
    private Connection conecta;
    
    public ClienteDAO(){
        this.conecta = ConnectionFactory.getInstance();
    }
    
    public void CadastrarCliente(ClienteModel obj){
        try{
            String cmdsql = "INSERT INTO cliente (nome,telefone,email) values (?,?,?)";
                    
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
