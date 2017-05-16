package prova2;

import javax.swing.*;
import javax.swing.JOptionPane;


public class JogoAdivinha extends Jogo{

   JogoAdivinha (String P[]) {
	   super(P,new JogadorAdivinha[3]);
	   String palavra;
	   brincaComPalavras();
	   JOptionPane.showMessageDialog(null,jogadores[vencedor()].nome + " ganhou!!!");
   }   
   void convidaJogadores () {
	   for (int i=0; i<3; i++)
		   jogadores[i] = new JogadorAdivinha(JOptionPane.showInputDialog("Escreva seu nome"));
   }
   void brincaComPalavras () {
	   do {
	      for (int i=0; i<3; i++) {
	         String palavra = JOptionPane.showInputDialog("Adivinhe uma palavra");
	         if (temPalavra(palavra))
	    	     jogadores[i].aumentaPontos();
	      }
	   } while (JOptionPane.showInputDialog("Quer parar? (s/n)").equals("n"));
   }
   boolean temPalavra (String p) {
	   for (int i = 0; i<palavras.length; i++)
		   if (palavras[i].equals(p))
			   return true;
	   return false;
   }
   public static void main (String args[]) {
       String p[] = { "boi", "pato", "rro"};
	   new JogoAdivinha(p);
   }
}