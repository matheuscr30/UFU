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
public interface BalanceResolver {
    public double balanceFor(Account account, Date date);
}
