package ntou.cs.java2025;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.Scanner;

public class EmployeeDataCollector {

	private Scanner input = new Scanner(System.in);
	private ArrayList<Employee> list = new ArrayList<Employee>();
	private int mode;
	private int employeeNumber=0;
	public EmployeeDataCollector () {
		input = new Scanner(System.in);
		list = new ArrayList<Employee>();
	}

	public void collectEmployeeData() {
		// TODO (會用到inputEmployeeData)
		printMenu();//印menu
		mode=input.nextInt();

		while(mode!=-1){
			Employee employee = null;
			switch (mode) {
				case 1:
					employee = new SalariedEmployee();
					break;
				case 2:
					employee = new HourlyEmployee();
					break;
				case 3:
					employee = new CommissionEmployee();
					break;
				case 4:
					employee = new PieceWorker();
					break;
				default:
					System.out.println("error");
					break;
			}

			if (employee != null) {
				inputEmployeeData(employee);//將employee加入arraylist
				employeeNumber++;
			}
			printMenu();
			mode = input.nextInt();
		}
		System.out.println("Input finished!");
		System.out.print(this.toString());
	}

	public void inputEmployeeData(Employee employee) {
		employee.inputData(input);
		setBonus(employee);
		list.add(employee);
	}

	public void setBonus(Employee employee) {
		System.out.print("Please input type of Bonus (1: static, 2: dynamic): ");
		int type = input.nextInt();
		Bonus bonus = null;
		if (type == 1) {
			bonus = new StaticBonus();
		}
		else{
			bonus = new DynamicBonus();
		}
		employee.setBonus(bonus);
	}

	public void printMenu(){
		System.out.println("---Earnings Calculation System:");
		System.out.println("1. Salaried Employee");
		System.out.println("2. Hourly Employee ");
		System.out.println("3. Commission Employee");
		System.out.println("4. Piece Worker");
		System.out.print("Please input (1~4, -1 to end):");
	}
	public String addComma(String s,int number){
		s += (number >= 1000)
				? NumberFormat.getInstance().format(number)
				: String.valueOf(number);
		return s;
	}
	@Override//print the details
	public String toString() {
		String result = "---Result:\n";
		int totalEarnings = 0;
		int totalBonus = 0;
		for (int i = 0; i < list.size(); i++) {
			Employee emp = list.get(i);
			int earning = emp.getEarnings();
			int bonus = emp.getBonus().getBonus(earning);
			totalEarnings += earning;
			totalBonus += bonus;
			result += "No. " + (i + 1) + ":\n";
			result += emp.toString();
			result = addComma(result +", calculated earnings: ", earning);
			result = addComma(result +", bonus: ", bonus);
			result+="\n";
		}
		result = addComma(result + "\nTotal earnings: ", totalEarnings);
		result = addComma(result + "\nTotal bonus: ", totalBonus);
		return result;
	}
}
