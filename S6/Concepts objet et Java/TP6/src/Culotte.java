import java.util.ArrayList;
import java.util.Hashtable;

public class Culotte {
    private int K, V;
    private Hashtable<String, Integer> table;

    public Culotte() {
        table = new Hashtable<>();
    }

    public void analyser(String texte) {
        String[] ss = texte.split(" ");
        for (String s: ss) {
            s.replaceAll("[^A-Za-z0-9_]", "");
            if(!s.isEmpty())
                if(table.containsKey(s))
                    table.replace(s, table.get(s).intValue() + 1);
                else
                    table.put(s, 0);
        }
    }

    public int fréquenceMot(String mot) {
        if(mot == null || table.containsKey(mot))
            return 0;
        return table.get(mot).intValue();
    }
}
