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
public class TabajaraException extends Exception {
	String mensagem;
	TabajaraException (String msg) {
		mensagem = msg;
	}
}
