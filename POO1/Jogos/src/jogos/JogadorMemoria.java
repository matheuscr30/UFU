/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package jogos;

/**
 *
 * @author ronistone
 */
public class JogadorMemoria extends Jogador{
    
    	int    rodadasGanhas;
	JogadorMemoria (String n) {
		super(n);
	}
	boolean melhor (JogadorMemoria outro) {
		if (this.rodadasGanhas > outro.rodadasGanhas)
			return true;
		return false;
	}
       void aumentaRodadasGanhas () {
    	   rodadasGanhas++;
       }
}
