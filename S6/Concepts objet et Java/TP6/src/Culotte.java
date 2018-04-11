
import java.util.*;

public class Culotte {
    static final public Comparator<Map.Entry<String, Long>> ENTRY_COMPARATOR = new Comparator<Map.Entry<String, Long>>() {
        @Override
        public int compare(Map.Entry<String, Long> o1, Map.Entry<String, Long> o2) {
            return o1.getValue() < o2.getValue() ? 1 : o1.getValue() > o2.getValue() ? -1 : 0;
        }
    };

    private Hashtable<String, Long> table;

    public Culotte() {
        table = new Hashtable<>();
    }

    public void analyser(String texte) {
        String[] ss = texte.split(" ");
        for (String s: ss) {
            s = s.replaceAll("[^A-Za-z0-9_'-]", "").toLowerCase();

            if (!s.isEmpty())
                if (table.containsKey(s))
                    table.replace(s, table.get(s) + 1);
                else
                    table.put(s, (long)1);
        }
    }

    public long fréquenceMot(String mot) {
        assert mot != null;
        if(table.containsKey(mot))
            return table.get(mot);
        return 0;
    }

    public Set<Map.Entry<String, Long>> entrySet() {
        return table.entrySet();
    }

    public List ordenedList() {
        List list = new ArrayList(entrySet());
        list.sort(ENTRY_COMPARATOR);
        return list;
    }
}
