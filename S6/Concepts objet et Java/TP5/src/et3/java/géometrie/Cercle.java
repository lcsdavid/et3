package et3.java.géometrie;

import java.awt.Color;
import java.awt.Point;

public class Cercle extends Forme {
    private int rayon;

    public Cercle() {
        super();
        rayon = 1;
    }

    public Cercle(Point centreGravité, Color couleur, int rayon) {
        super(centreGravité, couleur);
        if(rayon < 0) {
            System.getLogger("Le rayon doit être positif.");
            System.exit(-1);
        }
        this.rayon = rayon;
    }

    @Override
    public void translation(int x, int y) {
        centreGravité.move(x, y);
    }

    @Override
    public void homothétie(int ratio) {
        rayon *= ratio;
        if(ratio > 0)
            translation(centreGravité.x * (ratio - 1), centreGravité.y * (ratio - 1));
        else if(ratio < 0)
            translation(centreGravité.x * (ratio + 1), centreGravité.y * (ratio + 1));
    }

    @Override
    public String toString() {
        String s = "[Cercle\n   "
                + "[centre de gravité : x = " + centreGravité.x + ", y = " + centreGravité.y + "]\n   "
                + "[rayon : " + rayon + "]\n   "
                + "[couleur : r = " + couleur.getRed() + ", g = " + couleur.getGreen() + ", b = " + couleur.getBlue() + "]"
                + "\n]\n";
        return s;
    }
}
