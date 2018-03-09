package com.logique;

public class BasculeRS extends PorteLogique {
    protected PorteNOR porteNOR_R;
    protected PorteNOR porteNOR_S;

    public BasculeRS() {
        super();
        porteNOR_R = new PorteNOR();
        porteNOR_S = new PorteNOR();
    }

    public BasculeRS(boolean r, boolean s, boolean q) {
        super();
        porteNOR_R = new PorteNOR(r, q);
        porteNOR_S = new PorteNOR(q, s);
    }

    public boolean getQ() {
        return Q;
    }

    public boolean getNonQ() {
        return !Q;
    }

    public void setR(boolean r) {
        porteNOR_R.setA(r);
        actualiserQ();
    }

    public void setS(boolean s) {
        porteNOR_S.setB(s);
        actualiserQ();
    }

    @Override
    public void actualiserQ() {
        porteNOR_R.setB(!Q);
        porteNOR_S.setA(Q);
        Q = porteNOR_R.Q;
    }
}
