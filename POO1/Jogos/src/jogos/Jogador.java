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
public class Jogador {
    String nome;
    int    pontos;
    
    public Jogador(String n){
        nome = n;
    }
    void aumentaPontos () {
		pontos++;
    }
    boolean melhor (Jogador outro) {
		if (this.pontos > outro.pontos)
			return true;
		return false;
    }

    void aumentaRodadasGanhas() {
        throw new UnsupportedOperationException("Not supported yet.");
    }
}
