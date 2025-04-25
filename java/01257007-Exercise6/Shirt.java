package ntou.cs.java2025;
public class Shirt extends Clothing{
    private final String material;
    public Shirt(String name,double price,String size,String material){
        super(name,price,size);//call parent(clothing) construct
        this.material=material;
    }

    public String toString() {
        //call clothing's toString and add some info
        return super.toString() + " | Material: " + material;
    }
}