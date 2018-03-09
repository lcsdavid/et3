package com.logique;

public abstract class PorteLogique {
    protected boolean A;
    protected boolean B;
    protected boolean Q;

    public PorteLogique() {
        A = false;
        B = false;
    }

    public PorteLogique(boolean a, boolean b) {
        A = a;
        B = b;
    }

    public final void setA(boolean a) {
        A = a;
        actualiserQ();
    }

    public final void setB(boolean b) {
        B = b;
        actualiserQ();
    }

    public abstract void actualiserQ();

    public final boolean isQ() {
        return Q;
    }
}
