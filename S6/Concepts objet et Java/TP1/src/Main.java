import com.fêteforraine.Autotamponneuse;
import com.fêteforraine.PisteAutotamponneuse;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        Autotamponneuse a = new Autotamponneuse(5.0f, 2.0f);
        Autotamponneuse b = new Autotamponneuse(2.0f, 7.0f);
        System.out.println(a.toString());
        System.out.println(b.toString());
        System.out.println(a.distance(b));
        System.out.println(a.distance(null));
        System.out.println(a.collision(null));

        PisteAutotamponneuse p = new PisteAutotamponneuse(5);
        for(int i = 0; i < 100; i++) {
            p.dérèglementAléatoire();
        }
    }
}
