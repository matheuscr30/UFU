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
public class Jogador {
    private ArrayList<Carta> cartas;
    private Baralho bara;

    public Jogador()
    {
        cartas = new ArrayList<Carta>();
        bara = new Baralho();
    }
    
    public void sorteaCartas(Baralho bara)
    {
        Random gerador = new Random();
        int cont = 0;
        
        while(cont < 3)
        {
            int num = gerador.nextInt(27);
            ArrayList<Carta> vet = bara.getArrayCartas();
            Carta c = vet.get(num);
            
            if (!c.isEscolhido())
            {
                cartas.add(c);
                c.setEscolhido(true);
                cont++;
            }
        }  
    }
    
    public void zeraCartas()
    {
        cartas.clear();
    }

    public ArrayList<Carta> getCartas() {
        return cartas;
    }

    public void setCartas(ArrayList<Carta> cartas) {
        this.cartas = cartas;
    }

    public Baralho getBara() {
        return bara;
    }

    public void setBara(Baralho bara) {
        this.bara = bara;
    }
}
