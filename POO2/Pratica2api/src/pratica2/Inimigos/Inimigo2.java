/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica2.Inimigos;

import java.util.Observable;
import java.util.Observer;
import pratica2.Personagem;

/**
 *
 * @author matheus
 */
public class Inimigo2 implements Observer{
    
    private Observable coordsPersonagem;
    private double coord_x;
    private double coord_y;

    public Inimigo2(Observable coordsPersonagem){
        this.coordsPersonagem = coordsPersonagem;
        this.coordsPersonagem.addObserver(this);
    }
    
    @Override
    public void update(Observable o, Object o1) {
        Personagem p = (Personagem)o;
        System.out.println("Inimigo 2 descobriu a nova localizacao do Personagem"
                + "(x = " + p.getCoord_x() + ", y = " + p.getCoord_y() + ")");
    }
}
