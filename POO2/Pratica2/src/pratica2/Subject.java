/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica2;

/**
 *
 * @author matheus
 */
public interface Subject {
    void registrarObservador(Observer o);
    void removerObservadores(Observer o);
    void notificarObservadores();
}
