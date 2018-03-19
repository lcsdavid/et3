package com.logique;

import com.logique.io.*;
import com.logique.porte.NOR;

public final class BasculeRS {
    private Entrée R, S;
    private EntréeSortie Q, nonQ;
    private NOR NOR_R;
    private NOR NOR_S;

    public BasculeRS() {
        R = new Entrée();
        S = new Entrée();
        Q = new EntréeSortie();
        nonQ = new EntréeSortie(true);
        NOR_R = new NOR(R, nonQ, Q);
        NOR_S = new NOR(Q, S, nonQ);
    }

    public BasculeRS(boolean r, boolean s, boolean q) {
        R = new Entrée(r);
        S = new Entrée(s);
        Q = new EntréeSortie(q);
        nonQ = new EntréeSortie(!q);
        NOR_R = new NOR(R, nonQ, Q);
        NOR_S = new NOR(Q, S, nonQ);
    }

    public boolean Q() {
        return Q.valeur();
    }

    public boolean nonQ() {
        return nonQ.valeur();
    }

    public void R(boolean valeur) {
        if(S.valeur() && valeur)
            // TODO erreur
        R.valeur(valeur);
        NOR_R.calculer();
        nonQ.valeur(!Q.valeur());
    }

    public void S(boolean valeur) {
        if(R.valeur() && valeur)
            // TODO erreur
        S.valeur(valeur);
        NOR_S.calculer();
        Q.valeur(!nonQ.valeur());
    }

    @Override
    public String toString() {
        String s = "[R = " + R.valeur() + ", S = " + S.valeur() + ", Q = " + Q.valeur() + ", nonQ = " + nonQ.valeur()
                + "]\n";
        return s;
    }
}
