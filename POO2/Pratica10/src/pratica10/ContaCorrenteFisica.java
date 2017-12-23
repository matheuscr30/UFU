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
public class ContaCorrenteFisica extends Conta{

    @Override
    public void cadastrarPessoa() {
        Arra
        System.out.println("Cadastrando Pessoa na Conta Corrente de Pessoa Fisica");
    }

    @Override
    public void validarPessoa() {
        System.out.println("Validando Pessoa na Conta Corrente de Pessoa Fisica");
    }
    
    @Override
    public void configurarLimite(){
        System.out.println("Configurando Limite na Conta Corrente de Pessoa Fisica");
    }
    
    @Override
    public void solicitarCartaoCredito(){
        System.out.println("Configurando Limite na Conta Corrente de Pessoa Fisica");
    }
}
