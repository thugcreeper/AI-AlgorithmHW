package ntou.cs.java2025;

import java.text.NumberFormat;
import java.util.Scanner;

public class HourlyEmployee extends Employee{
    private int hours;
    private int hourlySalary;
    private int base;
    @Override
    public void inputData(Scanner input) {
        System.out.print("Please input hourly salary: ");
        hourlySalary = input.nextInt();
        System.out.print("Please input hours: ");
        hours = input.nextInt();
        base=hours*hourlySalary;
    }
    public String toString() {
        String result="Hourly Employee => hourly salary: ";
        if (hourlySalary >= 1000) {
            NumberFormat formatter = NumberFormat.getInstance();//每三位加一個逗號用的
            result += formatter.format(hourlySalary);
        }
        else {
            result += hourlySalary;
        }
        result+=", hours: "+hours;
        return result;
    }
    @Override
    public int getEarnings() {//若>40小時回傳?後的式子否則回傳:後的式子
        return (hours > 40) ? (int)(40*hourlySalary +(hours-40)*hourlySalary* 1.5) : base;
    }
}
