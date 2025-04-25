package ntou.cs.java2025;
import java.util.ArrayList;
import java.util.List;

public class ShoppingCart {
    private List<Product> items;

    public ShoppingCart() {
        items = new ArrayList<>();
    }

    public void addItem(Product product, int quantity) {
        product.setQuantity(quantity);
        items.add(product);
        System.out.print(product.toString());
        System.out.println(" | Subtotal: "+product.calculateProductItemPrice());
    }

    public double calculateTotalPrice() {//basic method
    double total=0.0d;
    for(Product item:items){
        total+=item.calculateProductItemPrice();
    }
        return total;
    }

    public double applyDiscount(double discountPercentage) {
        return  calculateTotalPrice()*(100-discountPercentage)/100;
    }
}
