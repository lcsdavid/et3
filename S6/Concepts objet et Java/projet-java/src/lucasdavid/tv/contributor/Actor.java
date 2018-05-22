package lucasdavid.tv.contributor;

import lucasdavid.xml.element.SimpleElement;
import org.jetbrains.annotations.NotNull;

/**
 * @author lucasdavid
 */
public class Actor extends Contributor {

    /**
     * Default constructor.
     * Allocates fields with empty values.
     *
     * @see Contributor#Contributor()
     */
    public Actor() {
        super();
    }

    /**
     * Constructor.
     *
     * @param name actor's name
     */
    public Actor(@NotNull String name) {
        this.name = name;
    }

    @Override
    protected void set(@NotNull SimpleElement simpleElement) {
        if(simpleElement.getText().contains("("))
            name = simpleElement.getText().split("[(]")[0].trim();
        else
            super.set(simpleElement);
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Actor) {
            return super.equals(obj);
        }
        return false;
    }
}
