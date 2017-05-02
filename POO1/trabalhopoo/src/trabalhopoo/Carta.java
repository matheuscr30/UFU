/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package trabalhopoo;

/**
 *
 * @author matheus
 */
//Ouro
//Copas
//Espadas
//Paus
public class Carta {
    private int valor;
    private char naipe;
    private boolean eh_manilha;
    private boolean escolhido, usado;
    private String imagem;
    
    public Carta(int valor, char naipe){
        this.valor = valor;
        this.naipe = naipe;
        this.eh_manilha = false;
        this.escolhido = false;
        this.usado = false;
        
        imagem = "";
        imagem += "/Imagens/";
        imagem += Integer.toString(valor);
        imagem += naipe;
        imagem += ".gif";
        //System.out.println(imagem);
        
        if (valor == 4 || valor == 7 || (naipe == 'E' && valor == 1))
            this.eh_manilha = true;
    }

    public String getImagem() {
        return imagem;
    }

    public void setImagem(String imagem) {
        this.imagem = imagem;
    }

    public boolean isEscolhido() {
        return escolhido;
    }

    public void setEscolhido(boolean escolhido) {
        this.escolhido = escolhido;
    }
    
    public int getValor() {
        return valor;
    }

    public void setValor(int valor) {
        this.valor = valor;
    }

    public boolean isUsado() {
        return usado;
    }

    public void setUsado(boolean usado) {
        this.usado = usado;
    }

    public char getNaipe() {
        return naipe;
    }

    public void setNaipe(char naipe) {
        this.naipe = naipe;
    }

    public boolean isEh_manilha() {
        return eh_manilha;
    }

    public void setEh_manilha(boolean eh_manilha) {
        this.eh_manilha = eh_manilha;
    }
}
