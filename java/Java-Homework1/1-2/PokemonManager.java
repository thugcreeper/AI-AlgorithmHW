package ntou.cs.java2025;
// Pokemon收藏管理器
class PokemonManager {
    private static final int MAX_SIZE = 10;
    private static Pokemon[] collection = new Pokemon[MAX_SIZE];
    private static int count = 0;

    // 靜態方法：新增Pokemon
    public static boolean add(Pokemon pokemon) {
        if (count >= MAX_SIZE || pokemon == null) {
            return false;
        }
        collection[count++] = pokemon;
        return true;
    }

    // 靜態方法：顯示所有Pokemon
    public static void showAll() {
        if (count==0) {
            System.out.println("No Pokemon%n");
            return;
        }
        for (int i=0; i<count;i++) {
            System.out.println(collection[i]);
        }
    }

    // 靜態方法：按類型查找Pokemon
    public static Pokemon[] findByType(PokemonType type) {
        int matchCount=0;
        for (int i=0;i<count;i++) {
            if (collection[i].getType()==type) {
                matchCount++;
            }
        }
        
        Pokemon[] result = new Pokemon[matchCount];
        int i=0;
        for (int j=0;j<count;j++) {
            if (collection[j].getType() == type) {
                result[i++] = collection[j];
            }
        }
        return result;
    }

    // 靜態方法：獲取最強的Pokemon
    public static Pokemon getStrongest() {
         if (count == 0) {
            return null;
        }
        Pokemon strongest = collection[0];
        for (int i=1;i<count;i++) {
            if (collection[i].getPower()>strongest.getPower()) {
                strongest = collection[i];
            }
        }
        return strongest;
    }
}