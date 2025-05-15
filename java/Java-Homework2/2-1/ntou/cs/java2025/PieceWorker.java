package ntou.cs.java2025;
import java.text.NumberFormat;
import java.util.Scanner;

public class PieceWorker extends Employee{
    private int wages;
    private int pieces;
    @Override
    public void inputData(Scanner input) {
        System.out.print("Please input wage: ");
        wages = input.nextInt();
        System.out.print("Please input piece: ");
        pieces = input.nextInt();
    }
    public String toString() {
        String result="Piece Worker => wage: ";
        if (wages >= 1000) {
            NumberFormat formatter = NumberFormat.getInstance();//每三位加一個逗號用的
            result += formatter.format(wages);
        }
        else {
            result += wages;
        }
        result += ", piece: "+pieces;
        return result;
    }
    @Override
    public int getEarnings() {
        return wages*pieces;
    }
}
