package lucasdavid.xml.element;

import java.util.*;
import java.util.function.Predicate;

import org.jetbrains.annotations.NotNull;

/**
 * Abstract is a model representing an abstract form of XML element (cf. DOM).
 *
 * @author lucasdavid
 */
public abstract class AbstractElement {
    protected String name;
    protected Map<String, String> attributes;

    private boolean lock;

    /**
     * Default constructor.
     * Allocates fields with empty values.
     */
    public AbstractElement() {
        name = "";
        attributes = new HashMap<>();

        lock = false;
    }

    /**
     *  Constructor.
     *
     * @param name name of this element
     * @param attributes attributes of this element
     */
    public AbstractElement(@NotNull String name, @NotNull Map<String, String> attributes) {
        this.name = name;
        this.attributes = attributes;

        lock = false;
    }

    /**
     * Returns {@link AbstractElement#lock} value.
     *
     * @return {@link AbstractElement#lock()}
     */
    public boolean isLock() {
        return lock;
    }

    /**
     * Replaces {@link AbstractElement#lock} by {@code true}.
     */
    public void lock() {
        lock = true;
    }

    /**
     * Returns {@link AbstractElement#name} value.
     *
     * @return {@link AbstractElement#name}
     */
    public String getName() {
        return name;
    }

    /**
     * Returns the value to which the specified key is mapped,
     * or {@code null} if {@link AbstractElement#attributes} map contains no mapping for the key.
     *
     * @param URI the key whose associated value is to be returned
     * @return the value to which the specified key is mapped,
     * or {@code null} if {@link AbstractElement#attributes} map contains no mapping for the key
     */
    public String getAttribute(@NotNull String URI) {
        return attributes.get(URI);
    }

    /**
     * Returns the value to which the specified index is,
     * in the array representation of {@link AbstractElement#attributes} map's values.
     *
     * @param index the index whose associated value is to be returned
     * @return the value to which the specified index is,
     * in the array representation of {@link AbstractElement#attributes} map's values.
     */
    public String getAttribute(int index) {
        assert index >= 0 && index < attributes.size();
        return (String) attributes.values().toArray()[index];
    }

    /**
     * Returns {@code true} if {@code attributes} is not empty, {@code false} otherwise.
     *
     * @return {@code true} if {@code attributes} is not empty, {@code false} otherwise
     */
    public boolean hasAttributes() {
        return !attributes.isEmpty();
    }

    /**
     * Sets {@link AbstractElement#name}.
     *
     * @param name name of this element
     */
    public void setName(@NotNull String name) {
        this.name = name;
    }

    /**
     * Associates the specified value with the specified key in {@link AbstractElement#attributes}.
     * @param URI key with which the specified value is to be associated
     * @param value value to be associated with the specified key
     */
    public void addAtribute(@NotNull String URI, @NotNull String value) {
        attributes.put(URI, value);
    }

    /**
     * Copies all of the mappings from the specified map to {@link AbstractElement#attributes}.
     * @param attributes mappings to be stored in {@link AbstractElement#attributes}.
     */
    public void addAllAttributes(@NotNull Map<String, String> attributes) {
        this.attributes.putAll(attributes);
    }

    /**
     * Queries {@code this} with a given {@link Predicate} filter.
     * If {@code this} is not an {@link Element}, returns an empty list or an one element list.
     * Otherwise, it keep all references which responds {@code true} to filter.
     *
     * @param filter filtering condition
     * @return a query of {@code this}
     */
    public List<AbstractElement> query(@NotNull Predicate<AbstractElement> filter) {
        List<AbstractElement> result = new ArrayList<>();
        if(filter.test(this))
            result.add(this);
        if(this instanceof Element) {
            Stack<AbstractElement> stack = new Stack<>();
            stack.addAll(((Element) this).getSubElements());
            while (!stack.empty())
                result.addAll(stack.pop().query(filter));
        }
        return result;
    }
}
