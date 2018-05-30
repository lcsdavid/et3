package tutoriel;

import javafx.scene.image.Image;
import javafx.scene.paint.Color;
import javafx.scene.paint.PhongMaterial;

import java.awt.font.ImageGraphicAttribute;


public class Sphere extends javafx.scene.shape.Sphere {
    private static final String DIFFUSE_MAP = "http://planetmaker.wthr.us/img/earth_gebco8_texture_8192x4096.jpg";
    private static final String NORMAL_MAP = "http://planetmaker.wthr.us/img/earth_normalmap_flat_8192x4096.jpg";
    private static final String SPECULAR_MAP = "http://planetmaker.wthr.us/img/earth_specularmap_flat_8192x4096.jpg";

    private static final double MAP_WIDTH  = 8192;
    private static final double MAP_HEIGHT = 4092;

    final private PhongMaterial material = new PhongMaterial();

    public Sphere() {
        this(1, Color.ORANGERED);
    }

    public Sphere(double radius, Color color) {
        super(radius);
        //material.setDiffuseMap(new Image(DIFFUSE_MAP, MAP_WIDTH, MAP_HEIGHT, true, true));
        //material.setBumpMap(new Image(NORMAL_MAP, MAP_WIDTH, MAP_HEIGHT, true, true));
        //material.setSpecularMap(new Image(SPECULAR_MAP, MAP_WIDTH, MAP_HEIGHT, true, true));
        //setMaterial(material);
    }

}
