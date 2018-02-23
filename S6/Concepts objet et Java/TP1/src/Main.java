import com.fêteforraine.Autotamponneuse;
import com.fêteforraine.PisteAutotamponneuse;

public class Main {

    public static void main(String[] args) {
        // Tests class Autotamponneuse
        System.out.println("Hello World!");
        Autotamponneuse a = new Autotamponneuse(5.0f, 2.0f);
        Autotamponneuse b = new Autotamponneuse(2.0f, 7.0f);
        System.out.println(a.toString());
        System.out.println(b.toString());
        System.out.println(a.distance(b));
        System.out.println(a.distance(null));
        System.out.println(a.collision(null));

        // Tests class PisteAutotamponneuse
        PisteAutotamponneuse p = new PisteAutotamponneuse(5);
        System.out.println("Configuration initiale:");
        System.out.println(p.toString());
        int i = 1;
        while(p.gagnante() == null) {
            System.out.println("Tour #" + i);
            p.dérèglementAléatoire();
            System.out.println(p.toString());
            i++;
        }
        System.out.println(p.gagnante().toString());
    }
}
