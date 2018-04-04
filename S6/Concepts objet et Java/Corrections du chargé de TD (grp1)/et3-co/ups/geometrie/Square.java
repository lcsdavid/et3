package ups.geometrie;

import java.awt.*;

public class Square extends Rectangle {

    public Square(Point center, double size) {
        super(center, Color.GREEN, size, size);
    }

    public void setWidth(double width) {
        super.setWidth(width);
        super.setHeight(height);
    }

    public void setHeight(double height) {
        setWidth(height);
    }

    @Override
    public String toString() {
        return "[Cercle\n" +
                "\t[centre de gravité : " + center + "]\n" +
                "\t[longueur : " + height + "]\n" +
                "\t[couleur : " + color + "]\n" +
                ']';
    }
}
