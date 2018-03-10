package com.logique;

public class Sortie extends EntréeSortie {
    private boolean val;

    public Sortie() {
        val = false;
    }

    public boolean getVal() {
        return val;
    }

    void setVal(boolean val) {
        this.val = val;
    }
}
