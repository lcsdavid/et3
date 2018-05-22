package lucasdavid.tv.contributor;

import org.jetbrains.annotations.NotNull;

/**
 * @author lucasdavid
 */
public class Director extends Contributor {

    /**
     * Default constructor.
     * Allocates fields with empty values.
     *
     * @see Contributor#Contributor()
     */
    public Director() {
        super();
    }

    /**
     * Constructor.
     *
     * @param name director's name
     */
    public Director(@NotNull String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Director) {
            return super.equals(obj);
        }
        return false;
    }
}
