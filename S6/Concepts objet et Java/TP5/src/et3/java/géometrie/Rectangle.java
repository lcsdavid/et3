package et3.java.géometrie;

import java.awt.Point;

public class Rectangle extends Forme {
    private Point a, b, c, d;

    public Rectangle() {
        a = new Point(-2, 1);
        b = new Point(2, 1);
        c = new Point(2, -1);
        d = new Point(-2, -1);
    }

    @Override
    public void translation(int x, int y) {
        centreGravité.move(x, y);
        a.move(x, y);
        b.move(x, y);
        c.move(x, y);
        d.move(x, y);
    }

    @Override
    public void homothétie(int ratio) {
        if (ratio > 0)
            translation(centreGravité.x * (ratio - 1), centreGravité.y * (ratio - 1));
        else if (ratio < 0)
            translation(centreGravité.x * (ratio + 1), centreGravité.y * (ratio + 1));
    }

    @Override
    public String toString() {
        String s = "[Rectangle\n    "
                + "[centre de gravité : x = " + centreGravité.x + ", y = " + centreGravité.y + "]\n    "
                + "[A : x = " + a.x + ", y = " + a.y + "]\n    "
                + "[B : x = " + b.x + ", y = " + b.y + "]\n    "
                + "[C : x = " + c.x + ", y = " + c.y + "]\n    "
                + "[D : x = " + d.x + ", y = " + d.y + "]\n    "
                + "[couleur : r = " + couleur.getRed() + ", g = " + couleur.getGreen() + ", b = " + couleur.getBlue() + "]"
                + "\n]\n";
        return s;
    }
}
