/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica11;
import java.util.ArrayList;
/**
 *
 * @author matheus
 */
public class Pilha {
    ArrayList<Node> pilha;
    int max;

    public Pilha(){
        pilha = new ArrayList<>();
        max = 10;
    }
    
    public void add(int v) throws Pilhaexcecao
    {
        if (pilha.size()+1 <= max)
            pilha.add(new Node(v));
        else
        {
            throw new Pilhaexcecao("Pilha Cheia");
        }
    }
    
    public int remove() throws Pilhaexcecao
    {
        int res;
        if (pilha.size()-1 >= 0)
        {
            res = pilha.get(pilha.size()-1).valor;
            pilha.remove(pilha.size()-1);
        }
        else
        {
            throw new Pilhaexcecao("Pilha Vazia");
        }
        
        return res;
    }
}
