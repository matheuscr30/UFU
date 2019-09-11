/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica8;

import pratica8.Factory.AtaqueFactory;
import pratica8.Factory.EscudoFactory;
import pratica8.Factory.InimigoFactory;
import pratica8.Factory.JogoFactory;

/**
 *
 * @author matheus
 */
public abstract class Jogo implements JogoFactory{
    protected AtaqueFactory ataqueFactory;
    protected EscudoFactory escudoFactory;
    protected InimigoFactory inimigoFactory;
    
    public Jogo() {
        ataqueFactory = AtaqueFactory.getInstance();
        escudoFactory = EscudoFactory.getInstance();
        inimigoFactory = InimigoFactory.getInstance();
    }
    
    public abstract void jogar();
}
