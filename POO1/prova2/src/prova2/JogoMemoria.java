/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package prova2;

/**
 *
 * @author matheus
 */
import javax.swing.*;
public class JogoMemoria extends Jogo{
   JogoMemoria (String P[], Jogador J[]) {
           super(P, J);
	   String palavra;
	   convidaJogadores();
	   brincaComPalavras();
	   JOptionPane.showMessageDialog(null,jogadores[vencedor()].nome + " ganhou!!!");
   }
   void convidaJogadores () {
	   int nroJogadores = Integer.parseInt(JOptionPane.showInputDialog("Digite nro. jogadores"));
	   palavras = new String[nroJogadores];
	   jogadores = new JogadorMemoria[nroJogadores];
	   for (int i=0; i<nroJogadores; i++) {
		   jogadores[i] = new JogadorMemoria(JOptionPane.showInputDialog("Escreva seu nome"));
		   palavras[i] = JOptionPane.showInputDialog("Forneça uma palavra qualquer");
	   }
   }
   void brincaComPalavras () {
      do {
         for (int i=0; i<jogadores.length; i++) {
      	    for (int j=0; j < jogadores.length; j++)
	       if (i!=j) {
	          String palavra = JOptionPane.showInputDialog(jogadores[i].nome +
                                                   ", lembre a palavra do "+jogadores[j].nome);
	          if (palavras[j].equals(palavra))
	    	       jogadores[i].aumentaPontos();
	    	}
	  }
	  jogadores[ganhadorRodada()].aumentaRodadasGanhas();
	  JOptionPane.showMessageDialog(null,"O ganhador da rodada foi " + jogadores[ganhadorRodada()].nome);
	      for (int i=0; i<jogadores.length;i++)
	    	  jogadores[i].pontos = 0;
	   } while (JOptionPane.showInputDialog("Quer parar? (s/n)").equals("n"));
   }
   
   int ganhadorRodada () {
	   int ganhador=0;
	   for (int i=1; i<jogadores.length; i++)
		   if (jogadores[i].pontos > jogadores[ganhador].pontos)
			   ganhador = i;	   
	   return ganhador;
   }
   public static void main (String args[]) {
	   new JogoMemoria(null, null);
   }
}
