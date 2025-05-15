package ntou.cs.java2025;
public class DynamicBonus implements Bonus {

	@Override
	public int getBonus(int salary) {
		//DynamicBonus sets the bonus as 10% of salary.
		return (int)(salary/10);
	}

}
