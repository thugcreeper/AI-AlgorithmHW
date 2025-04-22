package ntou.cs.java2025;
public class Clothing extends Product{
    private final String size;
    public Clothing(String name,double price,String size){
        super(name,price);//call parent construct
        this.size=size;
    }

    @Override 
    public double calculateProductItemPrice() {
        return getPrice() * getQuantity();
    }

    public String toString() {
        //call product's toString and add some info
        return super.toString() + " | Size: " + size;
    }
}
