package ups.gate;

public abstract class Gate {
    protected boolean inputA, inputB;
    protected boolean output;
    private long cycle = 0;

    public Gate() throws BrokenGateException {
        this(false, false);
    }

    public Gate(boolean inputA, boolean inputB) throws BrokenGateException {
        setInput(inputA, inputB);
    }

    public abstract boolean update();

    public void incrCycle() throws BrokenGateException {
        if (++cycle == maxCycles())
            throw new BrokenGateException("Broken gate", maxCycles());
    }

    public void setInputA(boolean inputA) throws BrokenGateException {
        this.inputA = inputA;
        this.output = update();
        incrCycle();
    }

    public void setInputB(boolean inputB) throws BrokenGateException {
        this.inputB = inputB;
        this.output = update();
        incrCycle();
    }

    public void setInput(boolean inputA, boolean inputB)
            throws BrokenGateException {
        this.inputA = inputA;
        this.inputB = inputB;
        this.output = update();
        incrCycle();
        incrCycle();
    }

    public boolean getOutput() throws BrokenGateException {
        incrCycle();
        return output;
    }

    protected abstract long maxCycles();

    @Override
    public String toString() {
        return "a=" + inputA + "\t| b=" + inputB + "\t| q=" + output;
    }
}
