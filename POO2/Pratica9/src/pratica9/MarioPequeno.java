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
public class MarioPequeno extends MarioState {

    public MarioPequeno(Mario mario) {
        super(mario);
    }
    
    @Override
    public void pegarCogumelo() {
        mario.setEstado(new MarioGrande(mario));
    }

    @Override
    public void pegarFlor() {
        mario.setEstado(new MarioFogo(mario));
    }

    @Override
    public void pegarPena() {
        mario.setEstado(new MarioPena(mario));
    }

    @Override
    public void levarDano() {
        mario.setEstado(new MarioMorto(mario));
    }
    
}
