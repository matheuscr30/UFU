/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package JDBC;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;


/**
 *
 * @author a11521BCC023
 */
public class ConnectionFactory {
    private volatile static Connection conexao;

    public ConnectionFactory() {
    }
    
    
    public static Connection getInstance(){
        if (conexao == null){
            synchronized (ConnectionFactory.class){
                if(conexao == null){
                    try{
                        conexao = DriverManager.getConnection("jdbc:mysql://localhost/banco", "root", "root");
                    }catch(SQLException e){
                        throw new RuntimeException(e);
                    }
                }
            }
        }
        
        return conexao;
    }
}
