package ups.geometrie;

import java.awt.*;
import java.util.ArrayList;

public class ShapeList extends ArrayList<Shape> {

    public void translate(int dx, int dy) {
        for (Shape s : this)
            s.translate(dx, dy);
    }

    public void translate(Point p) {
        translate(p.x, p.y);
    }

    public void homothety(double delta) {
        for (Shape s : this)
            s.homothety(delta);
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Shape s : this)
            sb.append(s);
        return sb.toString();
    }
}
