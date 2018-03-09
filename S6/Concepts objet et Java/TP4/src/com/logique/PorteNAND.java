package com.logique;

public class PorteNAND extends PorteLogique {

    public PorteNAND() {
        super();
        actualiserQ();
    }

    public PorteNAND(boolean a, boolean b) {
        super(a,b);
        actualiserQ();
    }

    @Override
    public void actualiserQ() {
        Q = !A || !B;
    }
}
