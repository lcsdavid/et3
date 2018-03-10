package et3.java.géometrie;

import java.awt.Color;
import java.awt.Point;

public abstract class Forme {
    protected Point centreGravité;
    protected Color couleur;

    Forme() {
        centreGravité = new Point();
        couleur = new Color(255,255,255);
    }

    Forme(Point centreGravité, Color couleur) {
        this.centreGravité = centreGravité;
        this.couleur = couleur;
    }

    public abstract void translation(int x, int y);

    public abstract void homothétie(int ratio);
}
