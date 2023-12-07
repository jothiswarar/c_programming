package Exercise7.Industry;

public class Expenses {
    private double machineryExpenses;
    private double rawMaterialExpenses;
    private double contingencies;

    public Expenses(double machineryExpenses, double rawMaterialExpenses, double contingencies) {
        this.machineryExpenses = machineryExpenses;
        this.rawMaterialExpenses = rawMaterialExpenses;
        this.contingencies = contingencies;
    }

    public double calculateTotalExpenses() {
        return machineryExpenses + rawMaterialExpenses + contingencies;
    }
}
