package lucasdavid.xml.element;

import org.jetbrains.annotations.NotNull;

import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.function.Predicate;

/**
 * @author lucasdavid
 */
public final class EmptyElement extends AbstractElement {

    /**
     * Default constructor.
     * @see AbstractElement#AbstractElement()
     */
    public EmptyElement() {
        super();
    }

    /**
     * Constructor.
     *
     * @param name to be set.
     * @param attributes to be set.
     * @see AbstractElement#AbstractElement(String, Map)
     */
    public EmptyElement(@NotNull String name, @NotNull Map<String, String> attributes) {
        super(name, attributes);

        lock();
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
        return stringBuilder.append(" />").toString();
    }
}
