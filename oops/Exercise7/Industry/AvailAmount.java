package Exercise7.Industry;
public class AvailAmount {
    private double assets;
    private double liabilities;
    private double salesDetails;

    public AvailAmount(double assets, double liabilities, double salesDetails) {
        this.assets = assets;
        this.liabilities = liabilities;
        this.salesDetails = salesDetails;
    }

    public double calculateProfit() {
        return salesDetails - (assets - liabilities);
    }
}
