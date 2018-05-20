package lucasdavid.tv;

import lucasdavid.xml.element.Element;
import lucasdavid.xml.element.NotExceptedElementException;
import lucasdavid.xml.element.SimpleElement;

import org.jetbrains.annotations.NotNull;

public class Channel {
    private String id;
    private String name;

    /**
     * Constructor.
     *
     * @param id to be set
     * @param name to be set
     */
    public Channel(@NotNull String id, @NotNull String name) {
        this.id = id;
        this.name = name;
    }

    /**
     * Constructor.
     * Extracts data from a given {@link Element}.
     *
     * @param element data container
     * @throws NotExceptedElementException If {@code element} not valid or miss data
     */
    public Channel(@NotNull Element element) throws NotExceptedElementException {
        if(!element.getName().equals("channel"))
            throw new NotExceptedElementException();
        id = ((SimpleElement) ((Element) element).getSubElements().get(0)).getText();
        name = ((SimpleElement) ((Element) element).getSubElements().get(1)).getText();
    }

    /* Getters */

    /**
     * Returns {@link Channel#id}.
     *
     * @return {@link Channel#id}
     */
    public String getId() {
        return id;
    }

    /**
     * Returns {@link Channel#name}.
     *
     * @return {@link Channel#name}
     */
    public String getName() {
        return name;
    }

    /**
     * Returns a {@link String} descriptor of {@code this}.
     *
     * @return a {@link String} descriptor of {@code this}.
     */
    @Override
    public String toString() {
        return "[" + getClass().getSimpleName() + ": " + name + ']';
    }
}
