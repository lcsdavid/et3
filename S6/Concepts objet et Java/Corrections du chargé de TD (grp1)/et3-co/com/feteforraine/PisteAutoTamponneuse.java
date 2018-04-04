package com.feteforraine;

public class PisteAutoTamponneuse {
    private Autotamponneuse autos [];

    public PisteAutoTamponneuse(int size) {
        autos = new Autotamponneuse[size];

        // Let's initialize all Autotamponneuse !
        for (int i = 0; i < autos.length; ++i) {
            autos[i] = new Autotamponneuse();
        }
    }

    public static void main(String args []) {
        double posX, posY;
        PisteAutoTamponneuse p = new PisteAutoTamponneuse(10);

        int i = 0, j;

        while (i < p.autos.length) {
            posX = Math.random() * Double.MAX_VALUE;
            posY = Math.random() * Double.MAX_VALUE;

            p.autos[i].place(posX, posY);
            for (j = 0; j < i; ++j) {
                if (p.autos[i].collision(p.autos[j])) break;
            }
            if (j == i) ++i;
        }
    }
}
