package ntou.cs.java2025;
import java.util.InputMismatchException;
import java.util.Scanner;

public class FuelCalculator {

	private static final GasStationBrand[] BRANDS = { null, new GasStationBrand("CPC", "Chinese Petroleum Corporation"),
			new GasStationBrand("FPCC", "Formosa Petrochemical Corporation"),
			new GasStationBrand("Costco", "Costco Wholesale") };

	public void calculateFuelUnitPrice() {
		boolean continueLoop=true;
		Scanner scanner = new Scanner(System.in);
	do{

		try{
			System.out.printf("%nPlease enter the cost of gasoline: ");
			int numerator = scanner.nextInt();
			System.out.print("Please enter the liters of gasoline: ");
			double denominator = scanner.nextDouble();
			System.out.print("Please enter the brand (1: CPC, 2: FPCC, 3: Costco): ");
			int brandNumber = scanner.nextInt();

			String brandName = BRANDS[brandNumber].getName();
			FuelRecord record = new FuelRecord(numerator, denominator, brandName);
			double result = record.costPerLiter();

			System.out.printf("Cost per liter of fuel for %s: %d / %.2f = %.2f%n", brandName, record.getFuelCost(),
					record.getLiters(), result);
			continueLoop=false;
		}
		catch(ArrayIndexOutOfBoundsException e){//index out of array's range
			System.err.printf("Exception: %s%n",e);
			System.out.println("You must enter a vaild brand number! Please try again.");
			scanner.nextLine();//清除輸入

		}
		catch(InputMismatchException e){//illegal input
			scanner.nextLine();//清除輸入
			System.err.printf("Exception: %s%n",e);
			System.out.println("You must enter integers. Please try again.");

		}
		catch(ArithmeticException e){//除以0
			System.err.printf("Exception: %s%n",e);
			System.out.println("You must enter liter greater than 0! Please try again.");
			scanner.nextLine();//清除輸入
		}
		catch(IllegalArgumentException e){
			System.err.printf("Exception: %s%n",e);
			System.out.println("please input a legal value! Please try again.");
			scanner.nextLine();//清除輸入
		}
		finally {
			System.out.println("Thank you for the test!");
		}

	}
	while(continueLoop);
		scanner.close();
	}
}
