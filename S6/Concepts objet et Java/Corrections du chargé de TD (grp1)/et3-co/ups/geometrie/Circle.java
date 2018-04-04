package ups.geometrie;

import java.awt.*;

public class Circle extends Shape {

    private double rayon;

    public Circle(Point center, Color color, double rayon) {
        super(center, color);
        this.rayon = rayon;
    }

    public Circle(Point center, double rayon) {
        super(center);
        this.rayon = rayon;
    }

    public Circle() {
        super();
        this.rayon = 0.d;
    }

    public double getRayon() {
        return rayon;
    }

    public void setRayon(double rayon) {
        this.rayon = rayon;
    }

    @Override
    public void homothety(double delta) {
        this.rayon *= delta;
    }

    @Override
    public String toString() {
        return "[Cercle\n" +
                "\t[centre de gravité : " + center + "]\n" +
                "\t[rayon : " + rayon + "]\n" +
                "\t[couleur : " + color + "]\n" +
                ']';
    }
}
