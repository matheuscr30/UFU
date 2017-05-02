/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalhopoo;
import java.awt.FlowLayout;
import javax.swing.*;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import static javax.swing.SwingConstants.CENTER;
/**
 *
 * @author matheus
 */
public class jogadorInterface extends JPanel{
    private JPanel jog, g1, g2;
    private JLabel t1, t2;
    private String espaco;
    private JButton carta1, carta2, carta3, b1, b2, b3;
    
    public jogadorInterface(int jogador, char dupla, Jogo jogo)
    {
        espaco = "                    ";
        jog = new JPanel(new GridLayout(4, 1));
        t1 = new JLabel("",CENTER);
        t1.setText("Jogador " + jogador  + espaco + "Dupla " + dupla);
        jog.add(t1);
        
        g1 = new JPanel(new GridLayout(1, 3, 5, 5));
        carta1 = new JButton("");
        carta1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
        carta2 = new JButton("");
        carta2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
        carta3 = new JButton("");
        carta3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
        g1.add(carta1);
        g1.add(carta2);
        g1.add(carta3);
        jog.add(g1);
       
        b1 = new JButton("Truco!!");
        b2 = new JButton("Correr");
        b3 = new JButton("Aceitar!");
        
        g2 = new JPanel(new GridLayout(1, 3));
        g2.add(b1);
        g2.add(b2);
        g2.add(b3);
        jog.add(g2);
        
        t2 = new JLabel("Quedas: ", CENTER);
        if (jogador == 1 || jogador == 4)
            jog.add(t2);
    }
    
    public String getEspaco() {
        return espaco;
    }

    public void setEspaco(String espaco) {
        this.espaco = espaco;
    }

    public JLabel getT1() {
        return t1;
    }

    public void setT1(JLabel t1) {
        this.t1 = t1;
    }

    public JLabel getT2() {
        return t2;
    }

    public void setT2(JLabel t2) {
        this.t2 = t2;
    }

    public JPanel getG1() {
        return g1;
    }

    public void setG1(JPanel g1) {
        this.g1 = g1;
    }

    public JPanel getG2() {
        return g2;
    }

    public void setG2(JPanel g2) {
        this.g2 = g2;
    }
    
    JPanel getJPanel()
    {
        return jog;
    }

    public JButton getCarta1() {
        return carta1;
    }

    public void setCarta1(JButton carta1) {
        this.carta1 = carta1;
    }

    public JButton getCarta2() {
        return carta2;
    }

    public void setCarta2(JButton carta2) {
        this.carta2 = carta2;
    }

    public JButton getCarta3() {
        return carta3;
    }

    public void setCarta3(JButton carta3) {
        this.carta3 = carta3;
    }

    public JButton getB1() {
        return b1;
    }

    public void setB1(JButton b1) {
        this.b1 = b1;
    }

    public JButton getB2() {
        return b2;
    }

    public void setB2(JButton b2) {
        this.b2 = b2;
    }

    public JButton getB3() {
        return b3;
    }

    public void setB3(JButton b3) {
        this.b3 = b3;
    }
}