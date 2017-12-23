/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica10;

/**
 *
 * @author matheus
 */
public abstract class Conta {

    private double dfsdfsdfsdf;

    public static void main()
    {
        sout
    }
    
    public final void depositarValorInicial(double valor){
        System.out.println("Realizando Deposito de :" + valor);
    }
    
    public final void cadastrarSenha(){
        System.out.println("Cadastrando Senha");
    }
    
    public final void finalizar(){
        System.out.println("Finalizando");
    }
    
    public void configurarLimite() { }
    public void solicitarCartaoCredito() { }
    
    public abstract void cadastrarPessoa();
    public abstract void validarPessoa();
}
