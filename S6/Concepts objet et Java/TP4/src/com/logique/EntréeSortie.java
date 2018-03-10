package com.logique;

public abstract class EntréeSortie {
    private boolean val;

    EntréeSortie() {
        val = false;
    }

    protected boolean getVal() {
        return val;
    }

    void setVal(boolean val) {
        this.val = val;
    }
}
