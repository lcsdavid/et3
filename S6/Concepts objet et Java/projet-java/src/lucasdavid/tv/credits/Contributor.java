package lucasdavid.tv.credits;

import lucasdavid.xml.element.SimpleElement;

public class Contributor {
    protected String name;

    public Contributor() {
        name = "";
    }

    protected void set(SimpleElement simpleElement) {
        assert simpleElement != null;
        name = simpleElement.getText();
    }

    public String getName() {
        return name;
    }

    static public Contributor newInstance(SimpleElement simpleElement) {
        assert simpleElement != null;
        Contributor contributor;
        switch (simpleElement.getName()) {
            case "actor":
                contributor = new Actor();
                break;
            case "director":
                contributor = new Director();
                break;
            case "guest":
                contributor = new Guest();
                break;
            case "presenter":
                contributor = new Presenter();
                break;
            case "writer":
                contributor = new Writer();
                break;
            default:
                contributor = new Contributor();
                break;
        }
        contributor.set(simpleElement);
        return contributor;
    }

    @Override
    public String toString() {
        return getClass().getSimpleName()+ ": " + name;
    }
}
