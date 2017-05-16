/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica;

/**
 *
 * @author matheus
 */

public class EmptyStackException extends RuntimeException {

    public EmptyStackException() {
        this("PILHA ESTA VAZIA");
    }

    public EmptyStackException(String exception) {
        super(exception);
    }

}
