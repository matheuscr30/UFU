/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8.Factory;

import pratica8.Acoes.Escudo;
import pratica8.TiposEscudos.EarthProtection;
import pratica8.TiposEscudos.SnowProtection;
import pratica8.TiposEscudos.WindProtection;

/**
 *
 * @author matheus
 */
public class EscudoFactory {
    
    private static EscudoFactory instance = null;
    
    private EscudoFactory() {
        
    }
    
    public static EscudoFactory getInstance() {
        if (instance == null) {
            synchronized (EscudoFactory.class) {
                if (instance == null) {
                    instance = new EscudoFactory();
                }
            }
        }        
        return instance;
    }
    
    public Escudo criaEscudo(String nivel) {
        Escudo escudo = null;
        
        if(nivel.equals("facil")){
            escudo = new EarthProtection();
        } 
        else if(nivel.equals("medio")){
            escudo = new WindProtection();
        } 
        else if(nivel.equals("dificil")){
            escudo = new SnowProtection();
        }
        
        return escudo;
    }    
}
