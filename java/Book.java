package ntou.cs.java2025;
public class Book extends Product{
    private final String author;
    public Book(String name,double price,String author){
        super(name,price);//call parent construct
        this.author=author;
    }
    @Override 
    public double calculateProductItemPrice() {
        return 0.9*getPrice() * getQuantity();
    }
    public String toString() {
        //call product's toString and add some info
        return super.toString() + " | Author: " + author;
    }
}