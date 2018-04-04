package ups.math;

import java.io.Serializable;
import java.util.ArrayList;

public class ComplexeMemoire extends Complexe implements Serializable {
    private ArrayList<String> history = new ArrayList<>();
    private static ArrayList<String> staticHistory = new ArrayList<>();

    public ComplexeMemoire(int re, int im) {
        super(re, im);
    }

    public ComplexeMemoire(ComplexeMemoire cmem) {
        super(cmem);
        // We call here the copy constructor of ArrayList<>.
        // If we had done `this.histo = cmem.histo`, we would had copy a
        // reference to object cmem. Therefore, changes to `this.histo`
        // would also affect `cmem.histo`.
        history = new ArrayList<>(cmem.history);
    }

    private ComplexeMemoire(Complexe c) {
        super(c);
    }

    private String opToString(Complexe other, String op, Complexe res) {
        return this + " " + op + " " + other + " = " + res;
    }

    private void addHistory (String entry) {
        history.add(entry);
    }

    public ArrayList<String> getHistory () {
        return new ArrayList<>(history);
        // Copy otherwise the caller could modifiy the reference
    }

    public static ArrayList<String> getStaticHistory() {
        return new ArrayList<>(staticHistory);
    }

    @Override
    public Complexe add(Complexe other) {
        ComplexeMemoire res = new ComplexeMemoire(super.add(other));
        String entry = opToString(other, "+", res);
        addHistory(entry);
        if (this.getClass() == other.getClass() && this != other) {
            ((ComplexeMemoire) other).addHistory(entry);
        }
        staticHistory.add(entry);
        return res;
    }

    @Override
    public Complexe mult(Complexe other) {
        ComplexeMemoire res = new ComplexeMemoire(super.mult(other));
        String entry = opToString(other, "*", res);
        addHistory(entry);
        if (this.getClass() == other.getClass() && this != other) {
            ((ComplexeMemoire) other).addHistory(entry);
        }
        staticHistory.add(entry);
        return res;
    }
}
