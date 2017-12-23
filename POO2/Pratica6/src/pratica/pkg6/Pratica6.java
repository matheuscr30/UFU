/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica.pkg6;

import java.util.Date;

/**
 *
 * @author matheus
 */
public class Pratica6 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        BalanceCalculatorA balance = new BalanceCalculatorA();
        BalanceCalculatorAdapter adapter = new BalanceCalculatorAdapter(balance);
        
        Account account = new Account(5);
        Date date = new Date();
        adapter.balanceFor(account, date);
    }
    
}
