package com.util;

public class Complexe {
    private double re, im;

    public Complexe() {
        re = 0;
        im = 0;
    }

    public Complexe(double re, double im) {
        this.re = re;
        this.im = im;
    }

    public Complexe(Complexe other) {
        this.re = other.re;
        this.im = other.im;
    }

    public double module() {
        return Math.sqrt(re * re + im * im);
    }

    public double arg() {
        return Math.acos(re / module());
    }

    public boolean additionner(Complexe complexe) {
        if(complexe == null)
            return false;
        re += complexe.re;
        im += complexe.im;
        return true;
    }

    public boolean soustraire(Complexe complexe) {
        if(complexe == null)
            return false;
        re -= complexe.re;
        im -= complexe.im;
        return true;
    }

    public boolean multiplier(Complexe complexe) {
        if(complexe == null)
            return false;
        double re = this.re;
        double im = this.im;
        this.re = re * complexe.re - im * complexe.im;
        this.im = re * complexe.im + im * complexe.re;
        return true;
    }

    public boolean diviser(Complexe complexe) {
        if(complexe == null)
            return false;
        complexe.im *= -1;
        multiplier(complexe);
        double d = Math.pow(complexe.re, 2) + Math.pow(complexe.im, 2);
        if(d == 0)
            return true;
        re /= d;
        im /= d;
        return true;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj == null || obj.getClass() != Complexe.class)
            return false;
        return re == ((Complexe) obj).re && im == ((Complexe)obj).im;
    }
}
