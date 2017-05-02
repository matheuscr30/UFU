/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalhopoo;
import java.awt.Color;
import javax.swing.*;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import static java.lang.Integer.min;
import java.util.ArrayList;

public final class Interface {
    private JFrame janela;
    private JPanel g0, j1, j2, j3, j4, central;
    private JMenuBar menuBar;
    private JMenuItem b1;
    private Jogo jogo;
    private JButton icon1, icon2, icon3, icon4;
    private jogadorInterface jog1, jog2, jog3, jog4;
    private JLabel t3;
    
    public Interface()
    {
        jogo = new Jogo();
        janela = new JFrame("Truco");
        janela.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        janela.setSize(900, 900);
        g0 = new JPanel(new GridLayout(3, 3));
        g0.setBorder(BorderFactory.createEmptyBorder(10,10,10,10));
        janela.add(g0);
        janela.setLocationRelativeTo(null);
        
        jog1 = new jogadorInterface(1, 'A', jogo);
        jog2 = new jogadorInterface(2, 'B', jogo);
        jog3 = new jogadorInterface(3, 'A', jogo);
        jog4 = new jogadorInterface(4, 'B', jogo);
        
        jog1.getJPanel().setBorder(BorderFactory.createLineBorder(Color.BLACK));
        jog2.getJPanel().setBorder(BorderFactory.createLineBorder(Color.BLACK));
        jog3.getJPanel().setBorder(BorderFactory.createLineBorder(Color.BLACK));
        jog4.getJPanel().setBorder(BorderFactory.createLineBorder(Color.BLACK));
        
        icon1 = new JButton("");
        icon2 = new JButton("");
        icon3 = new JButton("");
        icon4 = new JButton("");
        zeraCentral();
        
        central = new JPanel(new GridLayout(3, 3));
        central.add(new JLabel());
        central.add(icon1);
        central.add(new JLabel());
        central.add(icon2);
        t3 = new JLabel("", JLabel.CENTER);
        central.add(t3);
        central.add(icon3);
        central.add(new JLabel());
        central.add(icon4);
        central.add(new JLabel());
        
        j1 = jog1.getJPanel();
        j2 = jog2.getJPanel();
        j3 = jog3.getJPanel();
        j4 = jog4.getJPanel();
        
        g0.add(new JLabel());
        g0.add(j1);
        g0.add(new JLabel());
        g0.add(j4);
        g0.add(central);
        g0.add(j2);
        g0.add(new JLabel());
        g0.add(j3);
        
        atualizaJogo();
        
        b1 = new JMenuItem("Novo Jogo");
        b1.addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                jogo.NovoJogo();
                mudaCor();
                
                ArrayList<Carta> vetCartas1 = jogo.getJogadores().get(0).getCartas();
                ArrayList<Carta> vetCartas2 = jogo.getJogadores().get(1).getCartas();
                ArrayList<Carta> vetCartas3 = jogo.getJogadores().get(2).getCartas();
                ArrayList<Carta> vetCartas4 = jogo.getJogadores().get(3).getCartas();
                    
                JButton but1 = jog1.getCarta1();
                JButton but2 = jog1.getCarta2();
                JButton but3 = jog1.getCarta3();
                JButton but4 = jog2.getCarta1();
                JButton but5 = jog2.getCarta2();
                JButton but6 = jog2.getCarta3();
                JButton but7 = jog3.getCarta1();
                JButton but8 = jog3.getCarta2();
                JButton but9 = jog3.getCarta3();
                JButton but10 = jog4.getCarta1();
                JButton but11 = jog4.getCarta2();
                JButton but12 = jog4.getCarta3();
                
                    
                but1.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas1.get(0).getImagem())));
                but2.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas1.get(1).getImagem())));
                but3.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas1.get(2).getImagem())));
                but4.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas2.get(0).getImagem())));
                but5.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas2.get(1).getImagem())));
                but6.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas2.get(2).getImagem())));
                but7.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas3.get(0).getImagem())));
                but8.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas3.get(1).getImagem())));
                but9.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas3.get(2).getImagem())));
                but10.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas4.get(0).getImagem())));
                but11.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas4.get(1).getImagem())));
                but12.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas4.get(2).getImagem())));
                
                zeraCentral();
            }
            
        });
        
        verificaFinal();
        verificaJog1();
        verificaJog2();
        verificaJog3();
        verificaJog4();
        
        menuBar = new JMenuBar();
        JMenu opcoes = new JMenu("Opcoes");
        menuBar.add(opcoes);
        opcoes.add(b1);
        menuBar.add(new JMenu("Ajuda"));
        menuBar.add(new JMenu("Sobre"));
        janela.setJMenuBar(menuBar); 
       
        janela.setVisible(true);
    }
    
    public void verificaJog1()
    {
        jog1.getCarta1().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                
                if (jogo.getVez() == 1 && !jogo.isEscolheuA())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(0).getCartas().get(0).setUsado(true);
                    jogo.setVez(2);
                    jogo.setEscolheuB(false);
                    jogo.setEscolheuA(true);
                    
                    jog1.getCarta1().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon1.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(0).getCartas().get(0).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        jog1.getCarta2().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if (jogo.getVez() == 1 && !jogo.isEscolheuA())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(0).getCartas().get(1).setUsado(true);
                    jogo.setVez(2);
                    jogo.setEscolheuB(false);
                    jogo.setEscolheuA(true);
                    
                    jog1.getCarta2().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon1.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(0).getCartas().get(1).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        jog1.getCarta3().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if (jogo.getVez() == 1 && !jogo.isEscolheuA())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(0).getCartas().get(2).setUsado(true);
                    jogo.setVez(2);
                    jogo.setEscolheuB(false);
                    jogo.setEscolheuA(true);
                    
                    jog1.getCarta3().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon1.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(0).getCartas().get(2).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        //Truco
        jog1.getB1().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if (jogo.getVez() == 2)
                {
                    JOptionPane.showMessageDialog(null, "Jogador 1 pediu Truco!!");
                    jogo.setTruco(true);
                    jogo.setValendo(3);
                }
            }
            
        });
        
        
        //Correr
        jog1.getB2().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
               if ((jogo.getVez() == 3 || jogo.getVez() == 1) && jogo.isTruco())
               {
                   jogo.setPontosB(jogo.getPontosB()+1);
                   
                   if (jogo.getPontosB() >= 12)
                   {
                       jogo.setQuedasB(jogo.getQuedasB()+1);
                       jogo.NovoJogo();
                   }
                   
                   atualizaJogo();
                   novaRodada();
               }
            }
            
        });
        
        
        //Aceitar
        jog1.getB3().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if ((jogo.getVez() == 3 || jogo.getVez() == 1) && jogo.isTruco())
                {
                    jogo.setValendo(3);
                    t3.setText("TRUCADO");
                }
            }
            
        });
    }
    
    public void verificaJog2()
    {
        jog2.getCarta1().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                
                if (jogo.getVez() == 2 && !jogo.isEscolheuB())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(1).getCartas().get(0).setUsado(true);
                    jogo.setVez(3);
                    jogo.setEscolheuA(false);
                    jogo.setEscolheuB(true);
                    
                    jog2.getCarta1().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon3.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(1).getCartas().get(0).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        jog2.getCarta2().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if (jogo.getVez() == 2 && !jogo.isEscolheuB())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(1).getCartas().get(1).setUsado(true);
                    jogo.setVez(3);
                    jogo.setEscolheuA(false);
                    jogo.setEscolheuB(true);
                    
                    jog2.getCarta2().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon3.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(1).getCartas().get(1).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        jog2.getCarta3().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if (jogo.getVez() == 2 && !jogo.isEscolheuB())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(1).getCartas().get(2).setUsado(true);
                    jogo.setVez(3);
                    jogo.setEscolheuA(false);
                    jogo.setEscolheuB(true);
                    
                    jog2.getCarta3().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon3.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(1).getCartas().get(2).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        //Truco
        jog2.getB1().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if ((jogo.getVez() == 3))
                {
                    JOptionPane.showMessageDialog(null, "Jogador 2 pediu Truco!!");
                    jogo.setTruco(true);
                    jogo.setValendo(3);
                }
            }
            
        });
        
        
        //Correr
        jog2.getB2().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
               if ((jogo.getVez() == 2 || jogo.getVez() == 4) && jogo.isTruco())
               {
                   jogo.setPontosA(jogo.getPontosA()+1);
                   
                   if (jogo.getPontosA() >= 12)
                   {
                       jogo.setQuedasA(jogo.getQuedasA()+1);
                       jogo.NovoJogo();
                   }
                   
                   atualizaJogo();
                   novaRodada();
               }
            }
            
        });
        
        
        //Aceitar
        jog2.getB3().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if ((jogo.getVez() == 2 || jogo.getVez() == 4) && jogo.isTruco())
                {
                    jogo.setValendo(3);
                    t3.setText("TRUCADO");
                }
            }
            
        });
        
    }
    
    public void verificaJog3()
    {
        jog3.getCarta1().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                
                if (jogo.getVez() == 3 && !jogo.isEscolheuA())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.setVez(4);
                    jogo.getJogadores().get(2).getCartas().get(0).setUsado(true);
                    jogo.setEscolheuB(false);
                    jogo.setEscolheuA(true);
                    
                    jog3.getCarta1().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon4.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(2).getCartas().get(0).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        jog3.getCarta2().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if (jogo.getVez() == 3 && !jogo.isEscolheuA())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(2).getCartas().get(1).setUsado(true);
                    jogo.setVez(4);
                    jogo.setEscolheuB(false);
                    jogo.setEscolheuA(true);
                    
                    jog3.getCarta2().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon4.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(2).getCartas().get(1).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        jog3.getCarta3().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if (jogo.getVez() == 3 && !jogo.isEscolheuA())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(2).getCartas().get(2).setUsado(true);
                    jogo.setVez(4);
                    jogo.setEscolheuB(false);
                    jogo.setEscolheuA(true);
                    
                    jog3.getCarta3().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon4.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(2).getCartas().get(2).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        //Truco
        jog3.getB1().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if ((jogo.getVez() == 4))
                {
                    JOptionPane.showMessageDialog(null, "Jogador 3 pediu Truco!!");
                    jogo.setTruco(true);
                    jogo.setValendo(3);
                }
            }
            
        });
        
        
        //Correr
        jog3.getB2().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
               if ((jogo.getVez() == 3 || jogo.getVez() == 1) && jogo.isTruco())
               {
                   jogo.setPontosB(jogo.getPontosB()+1);
                   
                   if (jogo.getPontosB() >= 12)
                   {
                       jogo.setQuedasB(jogo.getQuedasB()+1);
                       jogo.NovoJogo();
                   }
                   
                   atualizaJogo();
                   novaRodada();
               }
            }
            
        });
        
        
        //Aceitar
        jog3.getB3().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if ((jogo.getVez() == 3 || jogo.getVez() == 1) && jogo.isTruco())
                {
                    jogo.setValendo(3);
                    t3.setText("TRUCADO");
                }
            }
            
        });
        
    }
    
    public void verificaJog4()
    {
        jog4.getCarta1().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                
                if (jogo.getVez() == 4 && !jogo.isEscolheuB())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(3).getCartas().get(0).setUsado(true);
                    jogo.setVez(1);
                    jogo.setEscolheuA(false);
                    jogo.setEscolheuB(true);
                    
                    jog4.getCarta1().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon2.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(3).getCartas().get(0).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        jog4.getCarta2().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if (jogo.getVez() == 4 && !jogo.isEscolheuB())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(3).getCartas().get(1).setUsado(true);
                    jogo.setVez(1);
                    jogo.setEscolheuA(false);
                    jogo.setEscolheuB(true);
                    
                    jog4.getCarta2().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon2.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(3).getCartas().get(1).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        jog4.getCarta3().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if (jogo.getVez() == 4 && !jogo.isEscolheuB())
                {
                    jogo.setRodada(jogo.getRodada()+1);
                    jogo.getJogadores().get(3).getCartas().get(2).setUsado(true);
                    jogo.setVez(1);
                    jogo.setEscolheuA(false);
                    jogo.setEscolheuB(true);
                    
                    jog4.getCarta3().setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
                    icon2.setIcon(new javax.swing.ImageIcon(getClass().getResource(jogo.getJogadores().get(3).getCartas().get(2).getImagem())));
                    verificaFinal();
                }
            }
            
        });
        
        //Truco
        jog4.getB1().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if ((jogo.getVez() == 1))
                {
                    JOptionPane.showMessageDialog(null, "Jogador 4 pediu Truco!!");
                    jogo.setTruco(true);
                    jogo.setValendo(3);
                }
            }
            
        });
        
        
        //Correr
        jog4.getB2().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
               if ((jogo.getVez() == 2 || jogo.getVez() == 4) && jogo.isTruco())
               {
                   jogo.setPontosA(jogo.getPontosA()+1);
                   
                   if (jogo.getPontosA() >= 12)
                   {
                       jogo.setQuedasA(jogo.getQuedasA()+1);
                       jogo.NovoJogo();
                   }
                   
                   atualizaJogo();
                   novaRodada();
               }
            }
            
        });
        
        
        //Aceitar
        jog4.getB3().addActionListener(new ActionListener(){
            @Override
            public void actionPerformed(ActionEvent e) {
                if ((jogo.getVez() == 2 || jogo.getVez() == 4) && jogo.isTruco())
                {
                    jogo.setValendo(3);
                    t3.setText("TRUCADO");
                }
            }
            
        });
        
    }
    
    public void novaRodada()
    {
        jogo.NovaRodada();
        mudaCor();
        
        ArrayList<Carta> vetCartas1 = jogo.getJogadores().get(0).getCartas();
        ArrayList<Carta> vetCartas2 = jogo.getJogadores().get(1).getCartas();
        ArrayList<Carta> vetCartas3 = jogo.getJogadores().get(2).getCartas();
        ArrayList<Carta> vetCartas4 = jogo.getJogadores().get(3).getCartas();
                    
        JButton but1 = jog1.getCarta1();
        JButton but2 = jog1.getCarta2();
        JButton but3 = jog1.getCarta3();
        JButton but4 = jog2.getCarta1();
        JButton but5 = jog2.getCarta2();
        JButton but6 = jog2.getCarta3();
        JButton but7 = jog3.getCarta1();
        JButton but8 = jog3.getCarta2();
        JButton but9 = jog3.getCarta3();
        JButton but10 = jog4.getCarta1();
        JButton but11 = jog4.getCarta2();
        JButton but12 = jog4.getCarta3();
                
                    
        but1.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas1.get(0).getImagem())));
        but2.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas1.get(1).getImagem())));
        but3.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas1.get(2).getImagem())));
        but4.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas2.get(0).getImagem())));
        but5.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas2.get(1).getImagem())));
        but6.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas2.get(2).getImagem())));
        but7.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas3.get(0).getImagem())));
        but8.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas3.get(1).getImagem())));
        but9.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas3.get(2).getImagem())));
        but10.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas4.get(0).getImagem())));
        but11.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas4.get(1).getImagem())));
        but12.setIcon(new javax.swing.ImageIcon(getClass().getResource(vetCartas4.get(2).getImagem())));
                
        zeraCentral();
        t3.setText("");
    }
    
    public void mudaCor()
    {
        switch(jogo.getVez())
        {
            case 1:
                jog1.getT1().setForeground(Color.RED);
                jog2.getT1().setForeground(Color.black);
                jog3.getT1().setForeground(Color.black);
                jog4.getT1().setForeground(Color.black);
                break;
                
            case 2:
                jog1.getT1().setForeground(Color.black);
                jog2.getT1().setForeground(Color.RED);
                jog3.getT1().setForeground(Color.black);
                jog4.getT1().setForeground(Color.black);
                break;
                
            case 3:
                jog1.getT1().setForeground(Color.black);
                jog2.getT1().setForeground(Color.black);
                jog3.getT1().setForeground(Color.RED);
                jog4.getT1().setForeground(Color.black);
                break;
            
            case 4:
                jog1.getT1().setForeground(Color.black);
                jog2.getT1().setForeground(Color.black);
                jog3.getT1().setForeground(Color.black);
                jog4.getT1().setForeground(Color.RED);
                break;
        }
    }
    
    public void atualizaJogo()
    {
        jog1.getT2().setText("Quedas: " + jogo.getQuedasA() + jog1.getEspaco() + "Tentos: " + jogo.getPontosA());
        jog4.getT2().setText("Quedas: " + jogo.getQuedasB() + jog1.getEspaco() + "Tentos: " + jogo.getPontosB());
    }
    
    public void verificaFinal()
    {
        ArrayList<Carta> vet = new ArrayList<>();
        //System.out.println(jogo.getRodada());
        if (jogo.getRodada() == 4)
        {
            jogo.setRodada(0);
            
            for (Jogador j : jogo.getJogadores())
            {
                int indice = 0;
                for(Carta c : j.getCartas())
                {
                    if (c.isUsado())
                        vet.add(c);
                }
                indice++;
            }
            
            ArrayList<Carta> ordem = jogo.getOrdem();
            int win = 25, win2=25, win3 = 25, win4 = 25;
            
            int indice = 0;
            for (Carta c : ordem)
            {
                if (vet.get(0).getValor() == c.getValor() && !vet.get(0).isEh_manilha() && !c.isEh_manilha())
                    win = indice;
                else if (vet.get(0).getValor() == c.getValor() && vet.get(0).isEh_manilha() && c.isEh_manilha() && vet.get(0).getNaipe() == c.getNaipe())
                    win = indice;
                
                if (vet.get(2).getValor() == c.getValor() && !vet.get(2).isEh_manilha() && !c.isEh_manilha())
                    win2 = indice;
                else if (vet.get(2).getValor() == c.getValor() && vet.get(2).isEh_manilha() && c.isEh_manilha() && vet.get(2).getNaipe() == c.getNaipe())
                    win2 = indice;
                
                if (vet.get(1).getValor() == c.getValor() && !vet.get(1).isEh_manilha() && !c.isEh_manilha())
                    win3 = indice;
                else if (vet.get(1).getValor() == c.getValor() && vet.get(1).isEh_manilha() && c.isEh_manilha() && vet.get(1).getNaipe() == c.getNaipe())
                    win3 = indice;
                
                if (vet.get(3).getValor() == c.getValor() && !vet.get(3).isEh_manilha() && !c.isEh_manilha())
                    win4 = indice;
                else if (vet.get(3).getValor() == c.getValor() && vet.get(3).isEh_manilha() && c.isEh_manilha() && vet.get(3).getNaipe() == c.getNaipe())
                    win4 = indice;
                
                indice++;
            }
            
            int x, y;
            
            //System.out.println(win + " " + win2);
            //System.out.println(win3 + " " + win4);
            
            if (win == win2) x = win;
            else x = min(win, win2);
            
            if (win3 == win4) y = win3;
            else y = min(win3, win4);
            
            System.out.println(x + " " + y);
            if (jogo.getCangou() == 1)
                jogo.setCangou(2);
            
            if (x < y)
            {
                if (jogo.getTurn() == 1)
                    jogo.setFirst(1);
                
                jogo.setAux1(jogo.getAux1()+1);
                
                if (win < win2)
                    jogo.setVez(1);
                else if (win2 < win)
                    jogo.setVez(3);
            }
            else if (y < x)
            {
                if (jogo.getTurn() == 1)
                    jogo.setFirst(2);
                
                jogo.setAux2(jogo.getAux2()+1);
                
                if (win3 < win4)
                    jogo.setVez(2);
                else if (win4 < win3)
                    jogo.setVez(4);
            }
            else{
                
                System.out.println(jogo.getTurn());
                if (jogo.getTurn() == 1)
                {
                    jogo.setCangou(1);
                    JOptionPane.showMessageDialog(null, "Cangou!! Maior carta na mesa");
                }
                else if (jogo.getTurn() == 2)
                {
                    jogo.setCangou(2);
                    
                    if (jogo.getFirst() == 1)
                        jogo.setAux1(jogo.getAux1()+1);
                    else if (jogo.getFirst() == 2)
                        jogo.setAux2(jogo.getAux2()+1);
                }
            }
            
            mudaCor();
            jogo.setEscolheuA(false);
            jogo.setEscolheuB(false);
            zeraCentral();
            jogo.ZeraResultado();
            jogo.setTurn(jogo.getTurn()+1);
        }
        
        
        if (jogo.getTurn() == 4 || jogo.getCangou() == 2)
        {
            //System.out.println(jogo.getAux1() + " " + jogo.getAux2());
            if (jogo.getAux1() >  jogo.getAux2())
                jogo.setPontosA(jogo.getPontosA()+jogo.getValendo());
            else if (jogo.getAux2() > jogo.getAux1())
                jogo.setPontosB(jogo.getPontosB()+jogo.getValendo());
            novaRodada();
        }
        
        if (jogo.getPontosA() >= 12)
        {
            jogo.setQuedasA(jogo.getQuedasA()+1);
            jogo.setPontosA(0);
            jogo.setPontosB(0);
            novaRodada();
        }
        else if(jogo.getPontosB() >= 12)
        {
            jogo.setQuedasB(jogo.getQuedasB()+1);
            jogo.setPontosA(0);
            jogo.setPontosB(0);
            novaRodada();
        }
        
        atualizaJogo();
    }
    
    public void zeraCentral()
    {
        icon1.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
        icon2.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
        icon3.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
        icon4.setIcon(new javax.swing.ImageIcon(getClass().getResource("/Imagens/back.gif")));
    }
    
    public static void main(String args[])
    {
        Interface in = new Interface();
    }
}
