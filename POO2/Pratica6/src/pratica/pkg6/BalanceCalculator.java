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
public interface BalanceCalculator {
    public double calculateBalance(Integer account, Calendar date);
}
