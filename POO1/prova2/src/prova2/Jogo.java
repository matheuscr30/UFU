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
public abstract class Jogo {
    public String palavras[];
    Jogador jogadores[];
    
    public Jogo(String palas[], Jogador j[])
    {
        this.palavras = palas;
        this.jogadores = (Jogador [])j;
    }
    
    public int vencedor () {
	   int maioral=0;
	   for (int i=1; i< jogadores.length; i++)
		   if (jogadores[i].melhor(jogadores[maioral]))
			   maioral = i;
	   return maioral;
   }
    
    boolean temPalavra (String p) {
	   for (int i = 0; i<palavras.length; i++)
		   if (palavras[i].equals(p))
			   return true;
	   return false;
   }
}
