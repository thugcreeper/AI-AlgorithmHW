package ntou.cs.java2025;
import java.security.SecureRandom;
import java.lang.Math;

public class Complex {
    private double real;
    private double imaginary;

    SecureRandom random = new SecureRandom();

    public Complex(){
        this.real = random.nextDouble();
        this.imaginary = random.nextDouble();
    }

    public Complex(double real, double imaginary){
        this.real = real;
        this.imaginary = imaginary;
    }

    public Complex add(Complex b){
        return new Complex(real + b.real, imaginary + b.imaginary);
    }

    public Complex subtract(Complex b){
        return new Complex( this.real - b.real, this.imaginary - b.imaginary);
    }
    public Complex multiply(Complex b){
        return new Complex(this.real*b.real - this.imaginary*b.imaginary,this.real * b.imaginary + this.imaginary * b.real);
    }
    public String toString() {
        if (imaginary >= 0) {
            return String.format("%.2f + %.2fi", real, imaginary);
        } else {
            return String.format("%.2f - %.2fi", real, Math.abs(imaginary));
        }
    }
}
