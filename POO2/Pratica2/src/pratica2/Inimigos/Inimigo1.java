/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica2.Inimigos;

import pratica2.Observer;
import pratica2.Personagem;
import pratica2.Subject;

/**
 *
 * @author matheus
 */
public class Inimigo1 implements Observer{
    
    private Subject coordsPersonagem;
    private double coord_x;
    private double coord_y;

    public Inimigo1(Subject coordsPersonagem){
        this.coordsPersonagem = coordsPersonagem;
        this.coordsPersonagem.registrarObservador(this);
    }
    
    @Override
    public void atualizar(double coord_x, double coord_y) {
        System.out.println("Inimigo 1 descobriu a nova localizacao do Personagem"
                + "(x = " + coord_x + ", y = " + coord_y + ")");
    }
}
