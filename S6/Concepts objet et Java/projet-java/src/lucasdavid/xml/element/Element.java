package lucasdavid.xml.element;

import org.jetbrains.annotations.NotNull;

import java.util.*;
import java.util.function.Predicate;

/**
 * @author lucasdavid
 */
public final class Element extends AbstractElement {
    private List<AbstractElement> subElements;

    /**
     * Default constructor.
     * Allocates fields with empty values.
     *
     * @see AbstractElement#AbstractElement()
     */
    public Element() {
        super();
        subElements = new ArrayList<>();
    }

    /**
     * Constructor.
     *
     * @param name name of this element
     * @param attributes attributes of this element
     * @see AbstractElement#AbstractElement(String, Map)
     */
    public Element(@NotNull String name, @NotNull Map<String, String> attributes) {
        super(name, attributes);
        subElements = new ArrayList<>();
    }

    /**
     * Constructor.
     *
     * @param name name of this element
     * @param attributes attributes of this element
     * @param subElements subs elements of this element
     * @see AbstractElement#AbstractElement(String, Map)
     */
    public Element(@NotNull String name, @NotNull Map<String, String> attributes, List<AbstractElement> subElements) {
        super(name, attributes);
        this.subElements = subElements;

        lock();
    }

    /**
     * Returns {@link Element#subElements}.
     *
     * @return {@link Element#subElements}
     */
    public List<AbstractElement> getSubElements() {
        return subElements;
    }

    /**
     * Appends the specified element to the end of {@link Element#subElements}.
     *
     * @param subElement {@link AbstractElement} to append to {@link Element#subElements}
     */
    public void addSubElement(@NotNull AbstractElement subElement) {
        subElements.add(subElement);
    }

    /**
     * Appends all of the elements in the specified collection to the end of
     * {@link Element#subElements}.
     *
     * @param subElements {@link List} containing elements to be added to {@link Element#subElements}
     */
    public void addAllSubElements(@NotNull List<? extends AbstractElement> subElements) {
        this.subElements.addAll(subElements);
    }

    /**
     * Queries {@code this} with a given {@link Predicate} filter.
     *
     * @param filter filtering condition
     * @return a query of {@code this}
     */
    @Override
    public List<AbstractElement> query(@NotNull Predicate<AbstractElement> filter) {
        List<AbstractElement> result = new ArrayList<>();
        if(filter.test(this))
            result.add(this);
        Stack<AbstractElement> stack = new Stack<>();
        stack.addAll(((Element) this).getSubElements());
        while (!stack.empty())
            result.addAll(stack.pop().query(filter));
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
            stringBuilder.append(' ').append(entry.getKey()).append("=\"").append(entry.getValue()).append('\"');
        stringBuilder.append(">\n");
        for (AbstractElement element: subElements)
            for(String split: element.toString().split("\n"))
                stringBuilder.append('\t').append(split).append('\n');
        return stringBuilder.append("</").append(name).append('>').toString();
    }
}
