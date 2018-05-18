package tv;

public class Channel {
    static Channel UNDEFINED;

    private String id;
    private String name;

    public Channel() {
        id = "NaN";
        name = "NaN";
    }

    public Channel(String id) {
        this.id = id;
        name = "NaN";
    }

    public String id() {
        return id;
    }

    public void setId(String id) {
        this.id = id;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "[Channel:\n\tid = " + id + "\n\tdisplay-name = " + name + "\n]";
    }
}
