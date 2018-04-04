package ups.geometrie;

import java.awt.*;
import java.util.ArrayList;

public class SpecializedShapeList<S extends Shape> extends ArrayList<S> {

    public void translate(int dx, int dy) {
        for (S s : this)
            s.translate(dx, dy);
    }

    public void translate(Point p) {
        translate(p.x, p.y);
    }

    public void homothety(double delta) {
        for (S s : this)
            s.homothety(delta);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (S s : this)
            sb.append(s);
        return sb.toString();
    }
}
