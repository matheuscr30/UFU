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
public abstract class Jogador {
    String nome;
    int pontos;
    
    public Jogador(String n){
        this.nome = n;
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
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }
}
