package ups.gate;

public class Nor extends Gate {

    public Nor() throws BrokenGateException {
        super();
    }

    public Nor(boolean inputA, boolean inputB) throws BrokenGateException {
        super(inputA, inputB);
    }

    @Override
    public boolean update() {
        return !(inputA || inputB);
    }

    @Override
    protected long maxCycles () { return 60; }

    @Override
    public String toString() {
        return "Nor:  " + super.toString();
    }
}
