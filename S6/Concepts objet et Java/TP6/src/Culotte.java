import java.util.Hashtable;

public class Culotte {
    private Hashtable<String, Integer> m_hash;

    public Culotte() {
        m_hash = new Hashtable<>();
    }

    public void analyser(String texte) {
        String[] ss = texte.split(" ");
        for (String s: ss) {
            s = s.replaceAll("[^A-Za-z0-9_'-]", "").toLowerCase();
            if (!s.isEmpty()) {
                m_hash.computeIfPresent(s, (k, v) -> m_hash.replace(k, v++));
                m_hash.putIfAbsent(s, 1);
            }
        }
    }

    public int fréquenceMot(String mot) {
        assert mot != null;
        if(m_hash.containsKey(mot))
            return m_hash.get(mot);
        return 0;
    }

}
