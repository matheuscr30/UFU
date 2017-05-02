/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalhopoo;
import java.util.ArrayList;
import java.util.Random;
/**
 *
 * @author matheus
 */
public class Baralho {
    private ArrayList<Carta> ArrayCartas;
    
    public Baralho()
    {
        ArrayCartas = new ArrayList<Carta>();
        String aux = "sOCEP";
        
        for (int i = 1; i <= 3; i++)
        { 
           for (int j = 1; j <= 4; j++)
            {
                Carta c = new Carta(i, aux.charAt(j));
                ArrayCartas.add(c);
            }
        }
        
        for (int i = 11; i <= 13; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                Carta c = new Carta(i, aux.charAt(j));
                ArrayCartas.add(c);
            }
        }
        
        Carta c1 = new Carta(4, 'P');
        Carta c2 = new Carta(7, 'C');
        Carta c3 = new Carta(7, 'O');
        
        ArrayCartas.add(c1);
        ArrayCartas.add(c2);
        ArrayCartas.add(c3);
    }
    
    public void esvaziaBaralho()
    {
        for (Carta c : ArrayCartas)
        {
            c.setEscolhido(false);
            c.setUsado(false);
        }
    }

    public ArrayList<Carta> getArrayCartas() {
        return ArrayCartas;
    }

    public void setArrayCartas(ArrayList<Carta> ArrayCartas) {
        this.ArrayCartas = ArrayCartas;
    }
}
