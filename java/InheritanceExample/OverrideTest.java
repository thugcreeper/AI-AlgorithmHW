class StoreOfGrandFather {
	// 祖父創業時的菜色
	public void orderNoodle() {
		System.out.println("傳統黃麵！");
	}
	
	public void printBrand() {
		System.out.println("基隆海派!");
	}	
}

class StoreOfFather extends StoreOfGrandFather {
	// 父親改良了 (這就是override)
	@Override
	public void orderNoodle() {
		System.out.println("營養白麵！");
	}

	// 新菜色
	public void orderRice() {
		System.out.println("台式滷肉飯！");
	}

	// 新菜色
	public void orderRiceNoodle() {
		System.out.println("北海岸海鮮米粉！");
	}
}

class StoreOfSon extends StoreOfFather {
	// 兒子再改良了
	@Override
	public void orderNoodle() {
		System.out.println("日本拉麵！");
	}

	// 兒子也改良了
	@Override
	public void orderRice() {
		System.out.println("牛肉蓋飯！");
	}
}

public class OverrideTest {
	public static void main(String[] args) {
		// 40年前的客人點菜
		System.out.println("40年前的客人點菜:");
		StoreOfGrandFather store1 = new StoreOfGrandFather();
		store1.orderNoodle();
		System.out.println();

		// 20年前的客人點菜
		System.out.println("20年前的客人點菜:");
		StoreOfFather store2 = new StoreOfFather();
		store2.orderNoodle(); // 會吃到白麵
		store2.orderRice();
		store2.orderRiceNoodle();
		System.out.println();

		// 現在的客人點菜
		System.out.println("現在的客人點菜:");
		StoreOfSon store3 = new StoreOfSon();
		store3.orderNoodle(); // 會吃到拉麵
		store3.orderRice(); // 會吃到跟20年前一樣的口味 -> 典型的繼承
		store3.orderRiceNoodle(); // 跟上面一樣
		System.out.println();

		// 40年前的老客人，到了目前的餐廳點餐，客人只認得祖父老店的菜單
		System.out.println("40年前的老客人，到了目前的餐廳點餐，客人只認得祖父老店的菜單:");
		StoreOfGrandFather store4 = store3; // 把目前的店裝成祖父的店
		store4.orderNoodle(); // 雖然以為是祖父老店，但會吃到拉麵，這就是典型的多型
		// store4.orderRice(); // 這行這樣寫會過不了，因為祖父的店沒賣飯
		System.out.println();

		// 20年前的老客人，到了目前的餐廳點餐，客人只認得父親老店的菜單
		System.out.println("20年前的老客人，到了目前的餐廳點餐，客人只認得父親老店的菜單");
		StoreOfFather store5 = store3; // 把目前的店裝成父親的店
		store5.orderNoodle(); // 雖然以為是父親老店，但會吃到拉麵 -> 典型的多型
		store5.orderRice(); // 雖然以為是父親老店，但會吃到牛肉蓋飯 -> 典型的多型
		System.out.println();
	}
}
