package ups.gate;

public class Nand extends Gate {

    public Nand() throws BrokenGateException {
        super();
    }

    public Nand(boolean inputA, boolean inputB) throws BrokenGateException {
        super(inputA, inputB);
    }

    @Override
    public boolean update() {
        return !(inputA && inputB);
    }

    @Override
    protected long maxCycles () { return 40; }

    @Override
    public String toString() {
        return "Nand: " + super.toString();
    }
}
