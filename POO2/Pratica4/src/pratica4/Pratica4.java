/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica4;

import pratica4.Acoes.Escudo;
import pratica4.Acoes.Ataque;
import pratica4.AtaqueAdicionais.Ataque2x;
import pratica4.AtaqueBehavior.SnowAttack;
import pratica4.AtaqueBehavior.WindAttack;
import pratica4.Personagens.Personagem1;
import pratica4.TiposEscudos.EarthProtection;
import pratica4.TiposEscudos.WindProtection;

/**
 *
 * @author matheus
 */
public class Pratica4 {

    /**
     * @param args the command line arguments
     */
    
    //Matheus Cunha Reis - 11521BCC030 
    //Matheus dos Santos Mendes - 11521BCC023
    
    public static void main(String[] args) {
        
        Personagem p1 = new Personagem1();
        Escudo escudo = new EarthProtection();
        escudo.setNext(new WindProtection());
        p1.setEscudo(escudo);
        
        Ataque a1 = new WindAttack();
        Ataque a2 = new SnowAttack();
        Inimigo i1 = new Inimigo(a1);
        i1.atacar(p1);
        i1.setAtaque(a2);
        i1.atacar(p1);
        i1.setAtaque(new Ataque2x(i1.getAtaque()));
        i1.atacar(p1);
    }
}
