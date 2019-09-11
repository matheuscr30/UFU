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
public class Mario {
    private MarioState estado;
    private int pontos;

    public Mario() {
        this.pontos = 0;
        estado = new MarioPequeno(this);
    }
    
    public void addPontos(int pontos){
        this.pontos += pontos;
    }
    
    public void pegarCogumelo(){
        estado.pegarCogumelo();
    }
    
    public void pegarFlor(){
        estado.pegarFlor();
    }
    
    public void pegarPena(){
        estado.pegarPena();
    }
    
    public void levarDano(){
        estado.levarDano();
    }

    public MarioState getEstado() {
        return estado;
    }

    public void setEstado(MarioState estado) {
        this.estado = estado;
    }
}
