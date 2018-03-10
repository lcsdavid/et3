package com.logique;

public abstract class PorteLogique {
    private Sortie Q;

    public PorteLogique() {
        Q = new Sortie();
    }

    public abstract void calculer();

    public final boolean isQ() {
        return Q.getVal();
    }
}
