
import et3.java.géometrie.*;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        ArrayList<Forme> list = new ArrayList<>();
        list.add(new Carré());
        list.add(new Cercle());
        list.add(new Rectangle());

        for(Forme f : list) {
            System.out.println(f.toString());
        }
    }


}
