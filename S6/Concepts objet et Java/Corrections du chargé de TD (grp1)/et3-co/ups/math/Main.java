package ups.math;

import java.io.*;

public class Main {
    public static void close(Closeable c) {
        if (c == null) return;
        try {
            c.close();
        } catch (IOException e) {}
    }

    public static void main(String [] args) {
        ComplexeMemoire cm = new ComplexeMemoire(10,10);
        Complexe c = (Complexe) cm;
        Complexe add = c.add(cm);
        System.out.println(cm.getHistory());

        String file = "demo.bin";
        FileOutputStream fileOut = null;
        ObjectOutputStream objectOut = null;
        FileInputStream fileIn = null;
        ObjectInputStream objectIn = null;

        try {
            fileOut = new FileOutputStream(file);
            objectOut = new ObjectOutputStream(fileOut);

            fileIn = new FileInputStream(file);
            objectIn = new ObjectInputStream(fileIn);

            objectOut.writeObject(c);
            ComplexeMemoire rc = (ComplexeMemoire) objectIn.readObject();
            System.out.println("equals: " + rc.equals(c));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        } finally {
            close(objectOut);
            close(fileOut);
            close(objectIn);
            close(fileIn);
        }
    }
}
