package com.logique.porte;

import com.logique.io.EntréeSortie;

public class NAND extends PorteLogique {
    public NAND() {
        super();
    }

    public NAND(EntréeSortie A, EntréeSortie B, EntréeSortie Q) {
        super(A, B, Q);
    }

    @Override
    public void calculer() {
        Q.valeur(!A.valeur() || !B.valeur());
    }
}
