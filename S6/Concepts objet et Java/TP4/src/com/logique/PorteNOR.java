package com.logique;

public class PorteNOR extends PorteLogique {

    public PorteNOR() {
        super();
        actualiserQ();
    }

    public PorteNOR(boolean a, boolean b) {
        super(a,b);
        actualiserQ();
    }

    @Override
    public void actualiserQ() {
        Q = !A && !B;
    }
}
