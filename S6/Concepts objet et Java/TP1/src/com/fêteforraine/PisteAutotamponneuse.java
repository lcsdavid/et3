package com.fêteforraine;

import java.util.ArrayList;

public class PisteAutotamponneuse {
    private static final double TAILLE_PISTE = 25;

    private int tailleCollection;
    private Autotamponneuse[] autotamponneuses;

    public PisteAutotamponneuse(int tailleCollection) {
        this.tailleCollection = tailleCollection;
        autotamponneuses = new Autotamponneuse[tailleCollection];
        for (int i = 0; i < tailleCollection; i++) {
            autotamponneuses[i] = new Autotamponneuse(TAILLE_PISTE * Math.random(), TAILLE_PISTE * Math.random());
            autotamponneuses[i].ajouterOccupant("Jean-" + autotamponneuses[i].hashCode());
            autotamponneuses[i].allumer();
            if (Math.random() > 0.50f)
                autotamponneuses[i].démarrerClignotement();
        }
    }

    public Autotamponneuse gagnante() {
        Autotamponneuse gagnante = null;
        for (Autotamponneuse autotamponneuse: autotamponneuses) {
            if(autotamponneuse.estAllumée()) {
                if (gagnante != null)
                    return null;
                gagnante = autotamponneuse;
            }
        }
        return gagnante;
    }

    public void dérèglementAléatoire() {
        for (Autotamponneuse autotamponneuse : autotamponneuses) {
            if(autotamponneuse.estAllumée())
                autotamponneuse.placer(TAILLE_PISTE * Math.random(), TAILLE_PISTE *  Math.random());
        }
        for (int i = 0; i < tailleCollection; i++) {
            for (int j = i + 1; j < tailleCollection; j++) {
                if (autotamponneuses[i].estAllumée() && autotamponneuses[j].estAllumée()) {
                    if (Autotamponneuse.collision(autotamponneuses[i], autotamponneuses[j])) {
                        autotamponneuses[i].éteindre();
                        autotamponneuses[j].éteindre();
                        autotamponneuses[i].placer(0, 0);
                        autotamponneuses[j].placer(0, 0);
                    }
                }
            }
        }

    }

    @Override
    public String toString() {
        String s = "Piste: \n";
        for (Autotamponneuse autotamponneuse : autotamponneuses) {
            s += autotamponneuse.toString() + '\n';
        }
        return s;
    }
}
