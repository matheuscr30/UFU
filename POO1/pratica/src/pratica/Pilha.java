package pratica;

/**
 *
 * @author matheus
 */

public class Pilha {

    private final int tam; 
    private int topo;       
    private int[] elementos;   

    public Pilha(int tama) {
        this.tam = tama;
        topo = -1;
        elementos = new int[tama];
    }

    public void push(int valor) {
        if (topo == tam - 1) {
            throw new FullStackException("PILHA ESTA CHEIA");
        }
        elementos[++topo] = valor;
    }

    public int pop() {
        
        if (topo == -1) {
            throw new EmptyStackException("PILHA ESTA VAZIA");
        }
        
        return elementos[topo--];
    }
}