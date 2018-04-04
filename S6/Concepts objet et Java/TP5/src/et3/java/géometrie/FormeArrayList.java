package et3.java.géometrie;

import java.util.ArrayList;

public class FormeArrayList extends ArrayList<Forme> {

    public void translation(int x, int y) {
        forEach(item -> item.translation(x,y));
    }

    public void homothétie(int ratio) {
        forEach(item -> item.homothétie(ratio));
    }

    @Override
    public String toString() {
        return "AFFICHAGE + APPROPRIé MDR\n" + super.toString();
    }
}
