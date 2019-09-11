/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica2;

import java.util.ArrayList;
import java.util.Observable;
import java.util.Observer;
import pratica2.Acoes.Pulo;
import pratica2.Acoes.Corre;
import pratica2.Acoes.Ataque;

/**
 *
 * @author matheus
 */
public class Personagem extends Observable {
    private Pulo pulo;
    private Ataque ataque;
    private Corre corre;
    private double coord_x;
    private double coord_y;
    
    public void mudouCoordenadas(){
        notifyObservers();
    }
    
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

    public double getCoord_x() {
        return coord_x;
    }

    public void setCoord_x(double coord_x) {
        this.coord_x = coord_x;
        setChanged();
        mudouCoordenadas();
    }

    public double getCoord_y() {
        return coord_y;
    }

    public void setCoord_y(double coord_y) {
        this.coord_y = coord_y;
        setChanged();
        mudouCoordenadas();
    }
}
