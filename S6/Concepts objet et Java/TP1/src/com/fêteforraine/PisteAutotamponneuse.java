package com.fêteforraine;

public class PisteAutotamponneuse {
    private int tailleCollection;
    private Autotamponneuse[] autotamponneuses;

    public PisteAutotamponneuse(int tailleCollection) {
        this.tailleCollection = tailleCollection;
        autotamponneuses = new Autotamponneuse[this.tailleCollection];
        for (Autotamponneuse autotamponneuse : autotamponneuses) {
//            autotamponneuse.placer(10.f * (float)Math.random(), 10.f * (float)Math.random());
  //          autotamponneuse.ajouterOccupant("Jean-" + autotamponneuse.hashCode());
    //        autotamponneuse.allumer();
      //      if(Math.random() > 0.50f)
        //        autotamponneuse.démarrerClignotement();
        }
    }

    @Override
    public String toString() {
        String s = "Piste: \n";
        for (Autotamponneuse autotamponneuse : autotamponneuses) {
            s += autotamponneuses.toString() + '\n';
        }
        return s;
    }

    public void dérèglementAléatoire() {
        for (Autotamponneuse autotamponneuse : autotamponneuses) {
            autotamponneuse.placer(10.f * (float)Math.random(), 10.f * (float)Math.random());
        }
        for (int i = 0; i < tailleCollection; i++) {
            for (int ii = i; i < tailleCollection; i++) {
                if(autotamponneuses[i].estAllumée() && autotamponneuses[ii].estAllumée())
                    if(autotamponneuses[i].collision(autotamponneuses[ii])) {
                        autotamponneuses[i].éteindre();
                        autotamponneuses[i].placer(0, 0);
                    }
            }
        }

    }
}
