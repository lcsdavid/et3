package com.util.MémoireComplexe;
import com.util.Complexe;

import java.io.Serializable;
import java.util.Vector;

public class MémoireComplexe extends Complexe implements Serializable {
    private Vector<String> opérations;

    public MémoireComplexe() {
        super();
        opérations = new Vector<String>();
    }

    public MémoireComplexe(double re, double im) {
        super(re, im);
        opérations = new Vector<String>();
    }

    public MémoireComplexe(MémoireComplexe other) {
        super((Complexe)other);
        opérations = new Vector<String>();
    }

    @Override
    public boolean additionner(Complexe complexe) {
        opérations.add("additionner");
        return super.additionner(complexe);
    }

    @Override
    public boolean soustraire(Complexe complexe) {
        opérations.add("soustraire");
        return super.soustraire(complexe);
    }

    @Override
    public boolean multiplier(Complexe complexe) {
        opérations.add("multiplier");
        return super.multiplier(complexe);
    }

    @Override
    public boolean diviser(Complexe complexe) {
        opérations.add("diviser");
        return super.diviser(complexe);
    }

    static final long serialVersionUID = 0;
}
