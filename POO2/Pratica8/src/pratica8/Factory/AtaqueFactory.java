/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8.Factory;

import pratica8.Acoes.Ataque;
import pratica8.AtaqueBehavior.EarthAttack;
import pratica8.AtaqueBehavior.SnowAttack;
import pratica8.AtaqueBehavior.WindAttack;

/**
 *
 * @author matheus
 */
public class AtaqueFactory {
    
    private static AtaqueFactory instance = null;
    
    private AtaqueFactory() {
        
    }
    
    public static AtaqueFactory getInstance() {
        if (instance == null) {
            synchronized (AtaqueFactory.class) {
                if (instance == null) {
                    instance = new AtaqueFactory();
                }
            }
        }
        
        return instance;
    }
    
    public Ataque criaAtaque(String nivel) {
        Ataque ataque = null;
        if(nivel.equals("facil")){
            ataque = new EarthAttack();
        } 
        else if(nivel.equals("medio")){
            ataque = new WindAttack();
        } 
        else if(nivel.equals("dificil")){
            ataque = new SnowAttack();
        }
        
        return ataque;
    }
    
}
