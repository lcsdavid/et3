package tutoriel;

import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;
import javafx.scene.shape.Box;

public class Cube extends Box {
    final private PhongMaterial material = new PhongMaterial();

    public Cube() {
        this(1);
    }

    public Cube(double size) {
        this(size, Color.SALMON);
    }

    public Cube(double size, Color color) {
        super(size, size, size);
        material.setDiffuseColor(color);
        material.setSpecularColor(color);
        setMaterial(material);
    }

}
