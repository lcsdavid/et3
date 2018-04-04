package ups.gate;

public class Main {

    private static void testGate(Gate gate) {
        final boolean [] bools = {true, false};

        try {
            for (boolean a : bools) {
                for (boolean b : bools) {
                    gate.setInput(a, b);
                    System.out.println(gate);
                }
            }
        } catch (Exception e) {
            System.err.println("Broken");
        }
    }

    private static void testRS(RS rs) {
        final boolean [] bools = {true, false};

        try {
            for (boolean r : bools) {
                for (boolean s : bools) {
                    rs.setR(r);
                    rs.setS(s);
                    System.out.println(rs);
                }
            }
        } catch (Exception e) {
            System.err.println("Broken");
        }
    }

    public static void main(String [] args) {
        try {
            testGate(new Nand());
            testGate(new Nor());
            testRS(new RS());
        } catch (Exception e) {
            System.err.println("Broken");
        }
    }
}
