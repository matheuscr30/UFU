/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica12;
import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
/**
 *
 * @author matheus
 */
public class Pratica12 {

    JPanel g1;
    JFrame janela;
    JTextField t1, t2, t3, t4, r1, r2;
    JLabel o1, o2;
    JButton b1, b2;
    
    public Pratica12() throws Exception{
        janela = new JFrame("Calculadora");
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setSize(500, 200);
        
        g1 = new JPanel(new GridLayout(2, 5));
        
        t1 = new JTextField("");
        t2 = new JTextField("");
        t3 = new JTextField("");
        t4 = new JTextField("");
        r1 = new JTextField("");
        r2 = new JTextField("");
        o1 = new JLabel("*");
        o2 = new JLabel("+");
        b1 = new JButton("=");
        b2 = new JButton("=");
        
        g1.add(t1);
        g1.add(o1);
        g1.add(t2);
        g1.add(b1);
        g1.add(r1);
        g1.add(t3);
        g1.add(o2);
        g1.add(t4);
        g1.add(b2);
        g1.add(r2);
        
        janela.add(g1);
        
        b1.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                
                try{
                    int n1 = Integer.parseInt(t1.getText());
                    int n2 = Integer.parseInt(t2.getText());
                
                    r1.setText(Integer.toString(n1*n2));
                }
                catch(Exception exce){
                    System.out.println(exce.getMessage());
                }
                
            }
        });
        
        b2.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e){
                
                try{
                    int n1 = Integer.parseInt(t3.getText());
                    int n2 = Integer.parseInt(t4.getText());
                
                    r2.setText(Integer.toString(n1+n2));
                }
                catch (Exception exce){
                    System.out.println(exce.getMessage());
                }
                
            }
        });
        
        janela.setVisible(true);
    }
    
    public static void main(String[] args) throws Exception {
        Pratica12 p = new Pratica12();
    }
    
}
