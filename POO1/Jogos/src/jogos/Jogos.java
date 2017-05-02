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
public abstract class Jogos {

    public String palavras[];
    Jogador jogadores[];
    
    public Jogos(String P[],Jogador J[]){
        palavras = P;
        jogadores = (Jogador[]) J;
        String palavra;
	   convidaJogadores();
	   brincaComPalavras();
	   JOptionPane.showMessageDialog(null,jogadores[vencedor()].nome + " ganhou!!!");
    }
    boolean temPalavra (String p) {
	   for (int i = 0; i<palavras.length; i++)
		   if (palavras[i].equals(p))
			   return true;
	   return false;
   }
    abstract void brincaComPalavras ();
    abstract void convidaJogadores();
    int vencedor () {
	   int maioral=0;
	   for (int i=1; i<3; i++)
		   if (jogadores[i].melhor(jogadores[maioral]))
			   maioral = i;
	   return maioral;
   }
}
