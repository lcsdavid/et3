

public class PorteNAND extends PorteLogique{
    public PorteNAND() {
        A = false;
        B = false;
        actualiserQ();
    }

    @Override
    public void actualiserQ() {
        Q = !A || !B;
    }
}
