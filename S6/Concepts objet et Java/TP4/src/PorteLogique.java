
public abstract class PorteLogique {
    protected boolean A;
    protected boolean B;
    protected boolean Q;

    public final void setA(boolean a) {
        A = a;
        actualiserQ();
    }

    public final void setB(boolean b) {
        B = b;
        actualiserQ();
    }

    public abstract void actualiserQ();

    public final boolean isQ() {
        return Q;
    }
}
