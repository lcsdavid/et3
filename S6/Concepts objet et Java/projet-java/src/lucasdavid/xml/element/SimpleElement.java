package lucasdavid.xml.element;

import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.function.Predicate;

/**
 * @author lucasdavid
 */
public final class SimpleElement extends AbstractElement {
    private String text;

    /**
     * Default constructor.
     *
     * @see AbstractElement#AbstractElement()
     */
    public SimpleElement() {
        super();
        text = "";
    }

    /**
     * Constructor.
     *
     * @param name name of this element
     * @param attributes attributes of this element
     * @param text text of this element
     * @see AbstractElement#AbstractElement(String, Map)
     */
    public SimpleElement(@NotNull String name, @NotNull Map<String, String> attributes, @NotNull String text) {
        super(name, attributes);
        this.text = text;

        lock();
    }

    /* Getters & Setters */
    public String getText() {
        return text;
    }
    public void setText(@NotNull String text) {
        this.text = text;
    }

    /**
     * Queries {@code this} with a given {@link Predicate} filter.
     * Returns an empty list or an one element list.
     *
     * @param filter filtering condition
     * @return a query of {@code this}
     */
    @Override
    public List<AbstractElement> query(@NotNull Predicate<AbstractElement> filter) {
        List<AbstractElement> result = new ArrayList<>();
        if(filter.test(this))
            result.add(this);
        return result;
    }

    /**
     * Returns a XHTML descriptor of {@code this}.
     *
     * @return a XHTML descriptor of {@code this}.
     */
    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder().append('<').append(name);
        for (Map.Entry<String, String> entry: attributes.entrySet())
            stringBuilder.append(' ').append(entry.getKey()).append(" = \"").append(entry.getValue()).append('\"');
        return stringBuilder.append(">\n\t").append(text).append("\n</").append(name).append('>').toString();
    }
}
