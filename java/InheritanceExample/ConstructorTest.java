public class ConstructorTest {
	public static void main(String args[]) {
		Square s1 = new Square();
		System.out.println();
		Square s2 = new Square("red");
	}
}

class Shape {
	public Shape() {
		this("white");//call帶有字串作為參數的建構子
		System.out.println("Creating a shape");
	}

	public Shape(String color) {
		System.out.println("Creating a shape in " + color);
	}
}

class Rectangle extends Shape {
	public Rectangle() {
		this("gray");
		System.out.println("Creating a rectangle");
	}

	public Rectangle(String color) {
		System.out.println("Creating a rectangle in " + color);
	}
}

class Square extends Rectangle {
	public Square() {
		System.out.println("Creating a square");
	}

	public Square(String color) {
		super(color);
		System.out.println("Creating a square in " + color);
	}
}
