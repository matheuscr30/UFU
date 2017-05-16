/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package teste;

/**
 *
 * @author matheus
 */
public class B {
       int x;
	public B (int i) {  x = i;	}
	void g () throws TabajaraException {
		if (x == 2) 
			throw new SidelmawException("Danou-se");
		else 
			throw new SiferrowException("Ferrou-se");
	}
}