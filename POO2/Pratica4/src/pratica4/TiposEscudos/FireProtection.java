/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica4.TiposEscudos;

import pratica4.Acoes.Escudo;
import pratica4.IDTipos;

/**
 *
 * @author matheus
 */
public class FireProtection extends Escudo {

    public FireProtection() {
        super(IDTipos.fire);
    }

    @Override
    public void defesaFeita() {
        System.out.println("Defesa Realizada Com FireProtection");
    }   
}
