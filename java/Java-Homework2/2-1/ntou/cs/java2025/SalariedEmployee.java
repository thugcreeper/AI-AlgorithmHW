package ntou.cs.java2025;

import java.text.NumberFormat;
import java.util.Scanner;

public class SalariedEmployee extends Employee{
    private int weeklySalary;
    private int weeks;
    @Override
    public void inputData(Scanner input) {
        System.out.print("Please input weekly salary: ");
        weeklySalary = input.nextInt();
        System.out.print("Please input working weeks: ");
        weeks = input.nextInt();
    }

    public String toString() {
        String result="Salaried Employee => weekly salary: ";
        if (weeklySalary >= 1000) {
            NumberFormat formatter = NumberFormat.getInstance();//每三位加一個逗號用的
            result += formatter.format(weeklySalary);
        }
        else {
            result += weeklySalary;
        }
        result+=", working weeks: "+weeks;
        return result;
    }

    @Override
    public int getEarnings() {
        return weeklySalary *weeks;
    }

}
