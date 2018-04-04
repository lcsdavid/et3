package ups.gate;

public class BrokenGateException extends GateException {
    public BrokenGateException() { super(); }
    public BrokenGateException(String str) { super(str); }
    public BrokenGateException(String str, long cycles) {
        super(str + cycles);
    }
}
