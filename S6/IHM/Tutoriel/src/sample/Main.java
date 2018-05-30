package sample;

import javafx.animation.Animation;
import javafx.animation.AnimationTimer;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Point3D;
import javafx.scene.*;
import javafx.scene.effect.Glow;
import javafx.scene.effect.PerspectiveTransform;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.transform.NonInvertibleTransformException;
import javafx.scene.transform.Rotate;
import javafx.scene.transform.Transform;
import javafx.scene.transform.Translate;
import javafx.stage.Stage;
import tutoriel.Cube;
import tutoriel.Sphere;

public class Main extends Application {



    public Rotate TitanEllipse;
    public Rotate TitanSpin;
    public Transform TitanTransform;

    @Override
    public void start(Stage primaryStage) throws Exception{
        // Parent root = FXMLLoader.load(getClass().getResource("sample.fxml"));
        Group root = new Group();
        Pane pane = new Pane(root);

        // Cube cube = new Cube();
        Sphere Aquamarine = new Sphere(1, Color.AQUAMARINE);
        Aquamarine.setTranslateY(-1);
        //Aquamarine.setEffect(new Glow(5));

        Cube Titan = new Cube(0.5, Color.FIREBRICK);
        Group TitanGroup = new Group(Titan);
        root.getChildren().add(TitanGroup);
        TitanGroup.setTranslateX(-4);

        //TitanTransform = new Translate(0.01, 0.01 ,0.01);
        TitanEllipse = new Rotate(1, 4, -1, 0, new Point3D(1, 4, 0));
        TitanSpin = new Rotate(8, 0,0,0, new Point3D(1, 1,1));

        // root.getChildren().add(cube);
        root.getChildren().add(Aquamarine);

        PerspectiveCamera camera = new PerspectiveCamera(true);
        Group cameraGroup = new Group(camera);
        root.getChildren().add(cameraGroup);

        /* Rotate */
        Rotate ry = new Rotate();
        ry.setAxis(Rotate.Y_AXIS);
        ry.setAngle(-15);

        /* Translate */
        Translate tz = new Translate();
        tz.setZ(-10);
        tz.setY(-1);

        cameraGroup.getTransforms().addAll(ry, tz);

        /* Light */
        /*PointLight light = new PointLight(Color.AQUAMARINE);
        light.setTranslateX(-180);
        light.setTranslateY(-90);
        light.setTranslateZ(-120);
        light.setScaleX(1.1);
        light.setScaleY(1.1);
        light.setScaleZ(1.1);*/
        //light.getScope().addAll(root);

        Scene scene = new Scene(pane, 1280, 720, true, SceneAntialiasing.BALANCED);
        scene.setCamera(camera);
        //scene.setFill(Color.BLACK);

        primaryStage.setTitle("Cube");
        primaryStage.setScene(scene);
        primaryStage.show();

        final long startNanoTime = System.nanoTime();
        new AnimationTimer() {
            public void handle(long currentNanoTime) {
                double t = (currentNanoTime - startNanoTime) / 1000000000.0;
                Aquamarine.setRotationAxis(new Point3D(1, 1 ,1));
                Aquamarine.setRotate(t * 100);
                TitanGroup.getTransforms().add(TitanEllipse);
                Titan.getTransforms().add(TitanSpin);
            }
        }.start();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
