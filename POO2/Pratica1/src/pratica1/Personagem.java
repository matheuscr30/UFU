/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica1;

/**
 *
 * @author matheus
 */
public abstract class Personagem {
    private Pulo pulo;
    private Ataque ataque;
    private Corre corre;
    
    public void atacar(){
        ataque.atacar();
    }
    
    public void pular(){
        pulo.pular();
    }
    
    public void corre(){
        corre.correr();
    }
    
    public Pulo getPulo() {
        return pulo;
    }

    public void setPulo(Pulo pulo) {
        this.pulo = pulo;
    }

    public Ataque getAtaque() {
        return ataque;
    }

    public void setAtaque(Ataque ataque) {
        this.ataque = ataque;
    }

    public Corre getCorre() {
        return corre;
    }

    public void setCorre(Corre corre) {
        this.corre = corre;
    }
}
