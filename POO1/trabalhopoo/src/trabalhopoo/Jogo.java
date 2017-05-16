package trabalhopoo;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.ArrayList;
/**
 *
 * @author matheus
 */
public class Jogo {
    private Baralho baralho;
    private ArrayList<Jogador> jogadores;
    private ArrayList<Carta> ordem;
    private int pontosA, pontosB, valendo, vez, turn, inicio, first;
    private int quedasA, quedasB, rodada, aux1, aux2, cangou;
    private boolean truco, ga1, ga2, escolheuA, escolheuB;
    
    public Jogo()
    {
        baralho = new Baralho();
        jogadores = new ArrayList<>();
        ordem = new ArrayList<>();
        
        ordem.add(new Carta(4, 'P'));
        ordem.add(new Carta(7, 'C'));
        ordem.add(new Carta(1, 'E'));
        ordem.add(new Carta(7, 'O'));
        
        for (int i = 3; i >= 2; i--)
        {
            ordem.add(new Carta(i, 'P'));
        }
        
        ordem.add(new Carta(1, 'P'));
        
        for (int i = 13; i >= 11; i--)
        {
            ordem.add(new Carta(i, 'P'));
        }
        
        Jogador j1 = new Jogador();
        Jogador j2 = new Jogador();
        Jogador j3 = new Jogador();
        Jogador j4 = new Jogador();
        
        jogadores.add(j4);
        jogadores.add(j3);
        jogadores.add(j2);
        jogadores.add(j1);
        
        quedasA = 0;
        quedasB = 0;
        vez = 0;
    }
    
    public void NovoJogo()
    {
        for (Jogador j : jogadores)
        {
            j.zeraCartas();
            j.sorteaCartas(baralho);
        }
        
        baralho.esvaziaBaralho();
        valendo = 1;
        vez = 1;
        inicio = turn = 1;
        pontosA = pontosB = cangou = 0;
        aux1 = aux2 = rodada = 0;
        escolheuA = escolheuB = truco = false;
    }
    
    public void NovaRodada()
    {
        for (Jogador j : jogadores)
        {
            j.zeraCartas();
            j.sorteaCartas(baralho);
            
            for (Carta c : j.getCartas())
            {
                c.setUsado(false);
            }
        }
        
        baralho.esvaziaBaralho();
        
        inicio++;
        vez = inicio;
        truco = false;
        rodada = cangou = 0;
        valendo = turn = 1;
        aux1 = aux2 = 0;
        escolheuA = false;
        escolheuB = false;
    }
    
    public void ZeraResultado()
    {
        for (Jogador j : jogadores)
        {   
            for (Carta c : j.getCartas())
            {
                c.setUsado(false);
            }
        }
    }

    public boolean isEscolheuA() {
        return escolheuA;
    }

    public void setEscolheuA(boolean escolheuA) {
        this.escolheuA = escolheuA;
    }

    public boolean isEscolheuB() {
        return escolheuB;
    }

    public ArrayList<Carta> getOrdem() {
        return ordem;
    }

    public void setOrdem(ArrayList<Carta> ordem) {
        this.ordem = ordem;
    }

    public void setEscolheuB(boolean escolheuB) {
        this.escolheuB = escolheuB;
    }

    public int getQuedasA() {
        return quedasA;
    }

    public void setQuedasA(int quedasA) {
        this.quedasA = quedasA;
    }

    public int getQuedasB() {
        return quedasB;
    }

    public void setQuedasB(int quedasB) {
        this.quedasB = quedasB;
    }
    
    public int getCangou() {
        return cangou;
    }

    public void setCangou(int cangou) {
        this.cangou = cangou;
    }

    public int getFirst() {
        return first;
    }

    public void setFirst(int first) {
        this.first = first;
    }

    public Baralho getBaralho() {
        return baralho;
    }

    public int getTurn() {
        return turn;
    }

    public void setTurn(int turn) {
        this.turn = turn;
    }

    public int getRodada() {
        return rodada;
    }

    public void setRodada(int rodada) {
        this.rodada = rodada;
    }

    public boolean isGa1() {
        return ga1;
    }

    public void setGa1(boolean ga1) {
        this.ga1 = ga1;
    }

    public boolean isGa2() {
        return ga2;
    }

    public void setGa2(boolean ga2) {
        this.ga2 = ga2;
    }

    public int getPontosA() {
        return pontosA;
    }

    public void setPontosA(int pontosA) {
        this.pontosA = pontosA;
    }

    public int getPontosB() {
        return pontosB;
    }

    public void setPontosB(int pontosB) {
        this.pontosB = pontosB;
    }

    public int getValendo() {
        return valendo;
    }

    public void setValendo(int valendo) {
        this.valendo = valendo;
    }

    public int getVez() {
        return vez;
    }

    public void setVez(int vez) {
        this.vez = vez;
    }

    public boolean isTruco() {
        return truco;
    }

    public void setTruco(boolean truco) {
        this.truco = truco;
    }

    public void setBaralho(Baralho baralho) {
        this.baralho = baralho;
    }

    public ArrayList<Jogador> getJogadores() {
        return jogadores;
    }

    public void setJogadores(ArrayList<Jogador> jogadores) {
        this.jogadores = jogadores;
    }

    public int getAux1() {
        return aux1;
    }

    public void setAux1(int aux1) {
        this.aux1 = aux1;
    }

    public int getAux2() {
        return aux2;
    }

    public void setAux2(int aux2) {
        this.aux2 = aux2;
    }
}
