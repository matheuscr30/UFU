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
public class MarioPena extends MarioState{

    public MarioPena(Mario mario) {
        super(mario);
    }
    
    @Override
    public void pegarCogumelo() {
        mario.addPontos(1000);
    }

    @Override
    public void pegarFlor() {
        mario.setEstado(new MarioFogo(mario));
    }

    @Override
    public void pegarPena() {
        mario.addPontos(1000);
    }

    @Override
    public void levarDano() {
        mario.setEstado(new MarioGrande(mario));
    }
    
}
