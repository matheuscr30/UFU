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
class JogadorAdivinha extends Jogador{
	JogadorAdivinha (String n) {
		super(n);
	}
        
	boolean melhor (JogadorAdivinha outro) {
		if (this.pontos > outro.pontos)
			return true;
		return false;
	}
}