package com.logique.porte;

import com.logique.io.EntréeSortie;

public class NON {
    private EntréeSortie E, S;

    public NON(EntréeSortie E, EntréeSortie S) {
        this.E = E;
        this.S = S;
    }

    public void calculer() {
        S.valeur(!E.valeur());
    }

    public void entrée(boolean valeur) {
        E.valeur(valeur);
    }

    public boolean sortie() {
        return S.valeur();
    }
}
