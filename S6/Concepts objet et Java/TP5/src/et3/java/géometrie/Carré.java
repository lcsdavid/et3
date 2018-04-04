package et3.java.géometrie;

import java.awt.*;
import java.awt.geom.Point2D;

public final class Carré extends Rectangle {
    public Carré() {
        super();
    }

    public Carré(Point a, Point b, Point c, Point d) {
        super(a, b, c, d);
        assert a.distance(b) == c.distance(d) && b.distance(c) == d.distance(a);
    }

}
