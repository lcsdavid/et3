package com.logique.porte;

import com.logique.io.*;

public abstract class PorteLogique {
    protected EntréeSortie A, B, Q;

    public PorteLogique() {
        A = new Entrée();
        B = new Entrée();
        Q = new Sortie();
    }

    public PorteLogique(EntréeSortie A, EntréeSortie B, EntréeSortie Q) {
        this.A = A;
        this.B = B;
        this.Q = Q;
    }

    public abstract void calculer();
}
