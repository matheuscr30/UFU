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
 * @author matheus
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
                        conexao = DriverManager.getConnection("jdbc:postgresql://localhost/poo", "postgres", "xxxxxxx");
                    }catch(SQLException e){
                        throw new RuntimeException(e);
                    }
                }
            }
        }
        
        return conexao;
    }
}
