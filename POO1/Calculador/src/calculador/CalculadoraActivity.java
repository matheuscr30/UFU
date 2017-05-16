/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calculador;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*; 

/**
 *
 * @author Matheus
 */
public class CalculadoraActivity extends JFrame {
    
    
    CalculadoraActivity(){
        super("Calculadora");
        
        criarMenu();
    }
    
    private void criarMenu(){
        //Painel Principal
        JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, 10, b11, b12, b13;
        setLayout(new BorderLayout());
        this.getRootPane().setBorder(BorderFactory.createEmptyBorder(20, 20, 20, 20));
        
        //Criando o TextField
        TextField inicio = new TextField();
        add(inicio, BorderLayout.NORTH);
        
        //Criando os Botões
        JPanel num = new JPanel(new GridLayout(5,3));
        add(num,BorderLayout.CENTER);
        
        String[] n = {"1","2","3","4","5","6","7","8","9"," ","0", " ", "=", " ", "C"}; 
        
        for(int i = 0; i<n.length; i++)
            num.add(new JButton(n[i]));
                        
        //Criando as Operações
        JPanel operacoes = new JPanel(new GridLayout(4,1));
        
        add(operacoes,BorderLayout.EAST);
        
        String[] op = {"+","-","/","*"};
        
        for(int j = 0; j<op.length; j++)
            operacoes.add(new JButton(op[j]));
        
        
        ActionListener trataTecla = new ActionListener(){
            
            @Override
            public void actionPerformed(ActionEvent e){
                JButton botaoClicado = (JButton)e.getSource();                
            }
        };
     
    }
    
}