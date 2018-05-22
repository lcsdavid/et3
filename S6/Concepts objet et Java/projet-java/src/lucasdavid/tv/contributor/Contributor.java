package lucasdavid.tv.contributor;

import lucasdavid.xml.element.AbstractElement;
import lucasdavid.xml.element.Element;
import lucasdavid.xml.element.NotExceptedElementException;
import lucasdavid.xml.element.SimpleElement;
import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

/**
 * @author lucasdavid
 */
public class Contributor {
    protected String name;

    /**
     * Default constructor.
     * Allocates fields with empty values.
     */
    public Contributor() {
        name = "";
    }

    /**
     * Constructor.
     *
     * @param name contributor's name
     */
    public Contributor(@NotNull String name) {
        this.name = name;
    }

    /**
     * Sets data from a given {@link SimpleElement}.
     *
     * @param simpleElement data container
     */
    protected void set(@NotNull SimpleElement simpleElement) {
        name = simpleElement.getText();
    }

    /**
     * Returns {@link Contributor#name}.
     *
     * @return {@link Contributor#name}
     */
    public String getName() {
        return name;
    }

    /**
     * Returns a new instance of {@link Contributor} and set data from a given {@link SimpleElement}.
     *
     * @param simpleElement data container
     * @return a new instance of {@link Contributor} from a given {@link SimpleElement}
     * @see Contributor#set(SimpleElement)
     */
    static public Contributor newInstance(@NotNull SimpleElement simpleElement) {

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

    /**
     * Returns a list of new instances of {@link Contributor} and set data from a given {@link Element}.
     *
     * @param element data container
     * @return a new instance of {@link Contributor} from a given {@link Element}
     * @see Contributor#newInstance(SimpleElement)
     * @throws NotExceptedElementException ...
     */
    static public List<Contributor> newInstances(@NotNull Element element) throws NotExceptedElementException {
        if (!element.getName().equals("credits"))
            throw new NotExceptedElementException("not \"credits\"");

        List<Contributor> contributors = new ArrayList<>();
        for (AbstractElement abstractElement: element.getSubElements()) {
            if(abstractElement instanceof SimpleElement) {
                SimpleElement simpleElement = (SimpleElement) abstractElement;
                contributors.add(newInstance(simpleElement));
            } else
                throw new NotExceptedElementException("not a SimpleElement");
        }
        return contributors;
    }

    @Override
    public int hashCode() {
        return Objects.hash(getClass(), name);
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Contributor) {
            return name.equals(((Contributor) obj).name);
        }
        return false;
    }

    @Override
    public String toString() {
        return getClass().getSimpleName()+ ": " + name;
    }
}
