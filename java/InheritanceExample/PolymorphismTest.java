public class PolymorphismTest {
	public static void main(String args[]) {
		GFather gf = new GFather();
		gf.methodB();
		System.out.println();
		Father f = new Father();
		f.methodB();
		System.out.println();
		Son s = new Son();
		s.methodB();
		System.out.println();

		// 將子類別的variable（指向子類別object）指定成父類別的variable
		GFather gf2 = f;
		System.out.println(gf2);
		gf2.methodB();
		System.out.println();

		// 將子類別的variable（指向子類別object）指定成(祖)父類別的variable
		GFather gf3 = s;
		System.out.println(gf3);
		gf3.methodB();
		System.out.println();

		/*
		// 將父類別的variable（指向父類別object）指定成子類別的variable (有錯) 
		Father f2 = gf;
		System.out.println(f2); 
		System.out.println();
		 
		// 將父類別的variable（指向子類別object）指定成子類別的variable (須修正) 
		Father f3 = gf2;
		System.out.println(f3); 
		System.out.println();
		 
		// 轉型成任意型態的物件 (須移除) 
		Father f4 = (Father) new String();
		*/
	}
}

class GFather {

	public GFather() {
		System.out.println("Creating GFather");
	}

	public GFather(int age) {
		System.out.println("Creating GFather, age:" + age);
	}

	public String toString() {
		return "I am Grandfather";
	}

	public void methodA() {
		System.out.println("Grandfather's method");
	}

	public void methodB() {
		methodA();
	}
}

class Father extends GFather {

	public Father() {
		System.out.println("Creating Father");
	}

	public Father(int age) {
		System.out.println("Creating Father, age:" + age);
	}

	public String toString() {
		return "I am Father";
	}

	public void methodA() {
		System.out.println("Father's method");
	}
}

class Son extends Father {

	public Son() {
		System.out.println("Creating Son");
	}

	public Son(int age) {
		System.out.println("Creating Son, age:" + age);
	}

	public String toString() {
		return "I am Son";
	}
}