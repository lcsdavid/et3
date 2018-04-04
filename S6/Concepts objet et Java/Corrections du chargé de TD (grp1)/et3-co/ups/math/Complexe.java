package ups.math;

import java.io.Serializable;

public class Complexe implements Serializable {
    private int re, im;

    public Complexe(int re, int im) {
        this.re = re;
        this.im = im;
    }

    public Complexe(Complexe c) {
        // Primitive types (boolean, char, int, double, ...) are copied !
        this.re = c.re;
        this.im = c.im;
    }

    public double modulus() {
        return Math.sqrt(re * re + im * im);
    }

    public double argument() {
        return Math.acos(re / modulus());
    }

    public Complexe add(Complexe c) {
        int re = this.re + c.re;
        int im = this.im + this.im;
        return new Complexe(re, im);
    }

    public Complexe mult(Complexe c) {
        int re = this.re * c.re - this.im * c.im;
        int im = this.re * c.im - this.im * c.re;
        return new Complexe(re, im);
    }

    public int getRe() { return this.re; }
    public int getIm() { return this.im; }

    @Override
    public boolean equals(Object o) {
        if (o == null) return false;
        if (o == this) return true;
        if (o.getClass() != this.getClass()) return false;
        // We can safely cast to Complexe now !
        Complexe c = (Complexe) o;
        return (this.re == c.re && this.im == c.im);
    }

    @Override
    public String toString() {
        return ("(" + re + " + " + im + "i)");
    }
}
