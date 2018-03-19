package com.logique.porte;

import com.logique.io.EntréeSortie;

public class NOR extends PorteLogique {
    public NOR() {
        super();
    }

    public NOR(EntréeSortie A, EntréeSortie B, EntréeSortie Q) {
        super(A, B, Q);
    }

    @Override
    public void calculer() {
        Q.valeur(!A.valeur() && !B.valeur());
    }
}
