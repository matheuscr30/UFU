/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica2;

import java.util.ArrayList;
import pratica2.Acoes.Pulo;
import pratica2.Acoes.Corre;
import pratica2.Acoes.Ataque;

/**
 *
 * @author matheus
 */
public abstract class Personagem implements Subject {
    private Pulo pulo;
    private Ataque ataque;
    private Corre corre;
    private double coord_x;
    private double coord_y;
    private ArrayList<Observer> observadores;
    
    public Personagem(){
        observadores = new ArrayList<Observer>();
    }

    @Override
    public void registrarObservador(Observer o) {
        observadores.add(o);
    }

    @Override
    public void removerObservadores(Observer o) {
        int i = observadores.indexOf(o);
        if(i >= 0){
            observadores.remove(i);
        }
    }

    @Override
    public void notificarObservadores() {
        observadores.forEach((o) -> {
            o.atualizar(coord_x, coord_y);
        });
    }
    
    public void mudouCoordenadas(){
        notificarObservadores();
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
        mudouCoordenadas();
    }

    public double getCoord_y() {
        return coord_y;
    }

    public void setCoord_y(double coord_y) {
        this.coord_y = coord_y;
        mudouCoordenadas();
    }
}
