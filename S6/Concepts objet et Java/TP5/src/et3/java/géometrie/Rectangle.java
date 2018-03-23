package et3.java.géometrie;

import java.awt.Point;

public class Rectangle extends Forme {
    protected Point a, b, c, d;

    public Rectangle() {
        super();
        a = new Point(-1, 1);
        b = new Point(1, 1);
        c = new Point(1, -1);
        d = new Point(-1, -1);
    }

    public Rectangle(Point a, Point b, Point c, Point d) {
        centreGravité.translate((b.x - a.x) / 2, (d.y - a.y) /2);
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
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
