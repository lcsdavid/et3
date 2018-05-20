package lucasdavid.tv;

import lucasdavid.xml.element.Element;
import lucasdavid.xml.element.SimpleElement;
import org.jetbrains.annotations.NotNull;

public class Channel {
    private String id;
    private String name;

    public Channel(@NotNull String id, @NotNull String name) {
        this.id = id;
        this.name = name;
    }

    /**
     * Construct {@link Channel} from a given {@link Element}.
     *
     * @param element
     */
    public Channel(@NotNull Element element) {
        if(!element.getName().equals("channel"))
            return;

        id = ((SimpleElement) ((Element) element).getSubElements().get(0)).getText();
        name = ((SimpleElement) ((Element) element).getSubElements().get(1)).getText();
    }

    /* Getters */
    public String getId() {
        return id;
    }
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
        return "Channel: " + name;
    }
}
