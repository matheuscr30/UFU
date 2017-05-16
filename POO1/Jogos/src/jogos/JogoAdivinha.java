/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jogos;

import javax.swing.JOptionPane;

/**
 *
 * @author ronistone
 */
public class JogoAdivinha extends Jogos{
    
    JogoAdivinha (String P[]) {
           super(P,new JogadorAdivinha[3]);
	   String palavra;
	   convidaJogadores();
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
	         if (temPalavra(palavra)){
	    	     jogadores[i].aumentaPontos();
                     System.out.println(jogadores[i].pontos);
                 }
	      }
	   } while (JOptionPane.showInputDialog("Quer parar? (s/n)").equals("n"));
   }
   public static void main (String args[]) {
            String P[] = {"boi", "cavalo", "pato", "galo", "peixe"};
	   new JogoAdivinha(P);
   }
}
