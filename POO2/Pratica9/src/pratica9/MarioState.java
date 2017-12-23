/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica9;

/**
 *
 * @author matheus
 */
public abstract class MarioState {
    
    protected Mario mario;

    public MarioState(Mario mario) {
        this.mario = mario;
    }
    
    public abstract void pegarCogumelo();
    public abstract void pegarFlor();
    public abstract void pegarPena();
    public abstract void levarDano();
}
