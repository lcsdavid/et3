package com.logique.porte;

import com.logique.io.EntréeSortie;

public class AND extends PorteLogique {
    public AND() {
        super();
    }

    public AND(EntréeSortie A, EntréeSortie B, EntréeSortie Q) {
        super(A, B, Q);
    }

    @Override
    public void calculer() {
        Q.valeur(A.valeur() && B.valeur());
    }
}
