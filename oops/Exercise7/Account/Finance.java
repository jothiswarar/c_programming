package Exercise7.Account;
import Exercise7.Industry.*;

public class Finance {
    public static void main(String[] args) {
        Expenses expenses = new Expenses(50000, 30000, 10000);
        AvailAmount availAmount = new AvailAmount(150000, 70000, 200000);

        double totalExpenses = expenses.calculateTotalExpenses();
        double profit = availAmount.calculateProfit();

        System.out.println("Total Expenses: $" + totalExpenses);
        System.out.println("Profit: $" + profit);
    }
}
