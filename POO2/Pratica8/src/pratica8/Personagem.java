/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8;

import pratica8.Acoes.Escudo;
import pratica8.Acoes.Ataque;
import pratica8.Acoes.Corre;
import pratica8.Acoes.Pulo;

/**
 *
 * @author matheus
 */
public abstract class Personagem {
    int nivelVida;
    Escudo escudo;
    Ataque ataque;
    Pulo pulo;
    Corre corre;

    public Personagem() {
        nivelVida = 100;
    }
    
    public void defender(Ataque a){
        boolean flag = escudo.defender(a.getId());
        
        if(!flag){
            nivelVida -= a.getDano();
            System.out.println("Vida Restante: " + nivelVida);
        }
    }

    public int getNivelVida() {
        return nivelVida;
    }

    public void setNivelVida(int nivelVida) {
        this.nivelVida = nivelVida;
    }

    public Escudo getEscudo() {
        return escudo;
    }

    public void setEscudo(Escudo escudo) {
        this.escudo = escudo;
    }

    public Ataque getAtaque() {
        return ataque;
    }

    public void setAtaque(Ataque ataque) {
        this.ataque = ataque;
    }

    public Pulo getPulo() {
        return pulo;
    }

    public void setPulo(Pulo pulo) {
        this.pulo = pulo;
    }

    public Corre getCorre() {
        return corre;
    }

    public void setCorre(Corre corre) {
        this.corre = corre;
    }
}