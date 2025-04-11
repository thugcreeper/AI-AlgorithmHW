//java ntou.cs.java2025.ConstructorTest
package ntou.cs.java2025;
public class ConstructorTest {
    public static void main(String args[]) {
        ThirdWriter writer = new ThirdWriter();
        writer.showLastLine();

    }
}

class BaseWriter {
    public BaseWriter() {
        System.out.println("1. A subclass cannot narrow the access scope of a parent class method.");
    }

    public BaseWriter(String param) {
        this();//call BaseWriter() print 1.
        System.out.println("2. There is no inheritance relationship between the constructors of a parent and child class.");
    }
}

class SecondWriter extends BaseWriter {
    public SecondWriter() {
        this(" ");//4. call 3.
        System.out.println("4. A subclass constructor will automatically (or manually) call the parent class constructor.");
    }

    public SecondWriter(String param) {
        super(" ");//3. call 2.
        System.out.println("3. A constructor of any class can call another constructor of the same class using this.");
    }

    public SecondWriter(String param1, int param2) {
        this();//5. call 4.
        System.out.println("5. The first line of a subclass constructor can only be either super or this, but not both.");
    }

    public SecondWriter(String param1, int param2, boolean param3) {
        this(" ",0);//6.call 5
        System.out.println("6. Declaring a static method in a subclass with the same signature as a parent class method is not an override.");
    }

    public void showLastLine() {
        System.out.println("9. If the parent and child classes are in different packages and the subclass redefines a package-private method of the parent class, it is not an override.");
    }

}

class ThirdWriter extends SecondWriter {
    public ThirdWriter() {
        this(" ");//8. call 7.
        System.out.println("8. The @Override annotation can be used to explicitly indicate that a method is overridden.");
    }

    public ThirdWriter(String param) {
        super(" ", 0, true);//call SecondWriter's constructor(6.)
        System.out.println("7. Redefining a private method of the parent class in the subclass is not an override.");
    }

    public void showLastLine() {
        super.showLastLine();//call SecondWriter's showLastline 
        System.out.println("10. If the parent and child classes are in different packages and the subclass redefines a public method of the parent class, it is an override.");
    }
}