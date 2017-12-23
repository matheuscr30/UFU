/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica.pkg6;

import java.util.Calendar;

/**
 *
 * @author matheus
 */
public class BalanceCalculatorA implements BalanceCalculator {
    @Override
    public double calculateBalance(Integer account, Calendar date){
        System.out.println("Metodo Legado A");
        return 0;
    }
}
