/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8.Factory;

import pratica8.AtaqueAdicionais.Ataque2x;
import pratica8.AtaqueAdicionais.Ataque3x;
import pratica8.AtaqueBehavior.EarthAttack;
import pratica8.AtaqueBehavior.SnowAttack;
import pratica8.AtaqueBehavior.WindAttack;
import pratica8.Inimigo;
import pratica8.Jogo;

/**
 *
 * @author matheus
 */
public class InimigoFactory {
    
    private static InimigoFactory instance = null;
    
    private InimigoFactory() {
        
    }
    
    public static InimigoFactory getInstance() {
        if (instance == null) {
            synchronized (InimigoFactory.class) {
                if (instance == null) {
                    instance = new InimigoFactory();
                }
            }
        }
        
        return instance;
    }
    
    public Inimigo criaInimigo(String nivel) {
        Inimigo inimigo = null;
        
        if(nivel.equals("facil")){
            inimigo = new Inimigo(new WindAttack());
        } 
        else if(nivel.equals("medio")){
            inimigo = new Inimigo(new Ataque2x(new EarthAttack()));
        } 
        else if(nivel.equals("dificil")){
            inimigo = new Inimigo(new Ataque3x(new SnowAttack()));
        }
        
        return inimigo;
    }
}
