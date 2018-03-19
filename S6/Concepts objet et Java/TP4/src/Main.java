import com.logique.BasculeRS;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        BasculeRS b = new BasculeRS(false, false , true);
        System.out.println(b.toString());
        b.S(true);
        System.out.println(b.toString());
        System.out.println(System.out.toString());
    }

}
