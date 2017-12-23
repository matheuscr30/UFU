/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pratica.pkg6;

import java.util.Calendar;
import java.util.Date;

/**
 *
 * @author matheus
 */
public class BalanceCalculatorAdapter implements BalanceResolver {
    private BalanceCalculator balanceCalculator;

    public BalanceCalculatorAdapter(BalanceCalculator balanceCalculator) {
        this.balanceCalculator = balanceCalculator;
    }

    @Override
    public double balanceFor(Account account, Date date) {
        Calendar calendar = Calendar.getInstance();
        calendar.setTime(date);
        return balanceCalculator.calculateBalance(account.getId(), calendar);
    }
}
