package ups.gate;

public class RS {
    private boolean r, s, q;
    private Nor nr, ns;

    public RS () throws BrokenGateException {
        this(false, false, false);
    }

    protected RS(boolean r, boolean s, boolean q) throws BrokenGateException {
        this.r = r; this.s = s; this.q = q;
        nr = new Nor(r, !q);
        ns = new Nor(s, q);
    }

    public boolean getR() {
        return r;
    }

    public boolean getS() {
        return s;
    }

    public boolean getQ() {
        return q;
    }

    public boolean getNotQ() {
        return !q;
    }

    public void setR(boolean r) throws BrokenRSException {
        this.r = r;
        boolean oldQ = q;
        try {
            nr.setInput(r, !oldQ);
            ns.setInput(s, nr.getOutput());
            this.q = nr.getOutput();
        } catch (BrokenGateException e) {
            throw new BrokenRSException("Need to repair:" + e.getMessage());
        }
    }

    public void setS(boolean s) throws BrokenRSException {
        this.s = s;
        boolean oldQ = q;
        try {
            ns.setInput(s, oldQ);
            nr.setInput(r, ns.getOutput());
            this.q = nr.getOutput();
        } catch (BrokenGateException e) {
            throw new BrokenRSException("Need to repair:" + e.getMessage());
        }
    }

    @Override
    public String toString() {
        return "R=" + r + "\t| S=" + s  + "\t| Q=" + q + "\t| !Q=" + !q;
    }
}
