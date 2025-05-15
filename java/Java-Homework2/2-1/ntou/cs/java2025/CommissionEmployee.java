package ntou.cs.java2025;
import java.text.NumberFormat;
import java.util.Scanner;

public class CommissionEmployee extends Employee{
    private double commissionRate;
    private int grossSales;
    @Override
    public void inputData(Scanner input) {
        System.out.print("Please input commission rate: ");
        commissionRate = input.nextDouble();
        System.out.print("Please input gross sales: ");
        grossSales = input.nextInt();
    }
    public String toString() {
        String result="Commission Employee => commission rate: "+commissionRate+", grossSales: ";
        if (grossSales >= 1000) {
            NumberFormat formatter = NumberFormat.getInstance();//每三位加一個逗號用的
            result += formatter.format(grossSales);
        }
        else {
            result += grossSales;
        }
        return result;
    }
    @Override
    public int getEarnings() {
        return (int)(commissionRate*grossSales);
    }
}
