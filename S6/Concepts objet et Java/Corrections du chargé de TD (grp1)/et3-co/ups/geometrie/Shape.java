package ups.geometrie;

import java.awt.*;

public abstract class Shape {
    protected Point center;
    protected Color color;

    public Shape(Point center, Color color) {
        this.center = center;
        this.color = color;
    }

    public Shape(Point center) {
        this(center, Color.BLUE);
    }

    public Shape() {
        this(new Point());
    }

    public Point getCenter() {
        // Beware of returning a copy of center, instead of a reference !
        return new Point(center);
    }

    public void setCenter(Point center) {
        this.center = new Point(center);
    }

    public Color getColor() {
        return color;
    }

    public void setColor(Color color) {
        this.color = color;
    }

    public void translate(int dx, int dy) {
        center = new Point(center.x + dx, center.y + dy);
    }

    public void translate(Point p) {
        translate(p.x, p.y);
    }

    public abstract void homothety(double delta);
}
