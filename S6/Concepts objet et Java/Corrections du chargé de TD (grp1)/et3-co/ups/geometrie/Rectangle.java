package ups.geometrie;


import java.awt.*;

public class Rectangle extends Shape {
    protected double width, height;

    public Rectangle(Point center, Color color, double width, double height) {
        super(center, color);
        this.width = width;
        this.height = height;
    }

    public Rectangle(Point center, double width, double height) {
        this(center, Color.RED, width, height);
    }

    public Rectangle(double width, double height) {
        this(new Point(), width, height);
    }

    public Rectangle() {
        this(0, 0);
    }

    public double getWidth() {
        return width;
    }

    public void setWidth(double width) {
        this.width = width;
    }

    public double getHeight() {
        return height;
    }

    public void setHeight(double height) {
        this.height = height;
    }

    @Override
    public void homothety(double delta) {
        this.width = width * delta;
        this.height = height * delta;
    }

    @Override
    public String toString() {
        return "[Cercle\n" +
                "\t[centre de gravité : " + center + "]\n" +
                "\t[largeur : " + width + "]\n" +
                "\t[hauteur : " + height + "]\n" +
                "\t[couleur : " + color + "]\n" +
                ']';
    }
}
