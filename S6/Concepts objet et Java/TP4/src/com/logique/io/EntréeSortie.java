package com.logique.io;

public class EntréeSortie {
    private boolean valeur;

    public EntréeSortie() {
        valeur = false;
    }

    public EntréeSortie(boolean valeur) {
        this.valeur = valeur;
    }

    public boolean valeur() {
        return valeur;
    }

    public void valeur(boolean valeur) {
        this.valeur = valeur;
    }
}
