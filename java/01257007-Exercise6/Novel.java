package ntou.cs.java2025;
public class Novel extends Book{
    private final String genre;
    public Novel(String name,double price,String author,String genre){
        super(name,price,author);//call parent(book) construct
        this.genre=genre;
    }

}