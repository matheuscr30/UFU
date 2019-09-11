/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package ComandoPanelaEletrica;

import Aparelhos.PanelaEletrica;
import com.matheus.Comando;


/**
 *
 * @author msantome
 */
public class ComandoLigarPanela implements Comando{
    private PanelaEletrica panEletrica;
    
    public ComandoLigarPanela(PanelaEletrica panelinha){
        this.panEletrica = panelinha;
    }

    @Override
    public void executar(){
        panEletrica.ligarPanela();
    }
}
