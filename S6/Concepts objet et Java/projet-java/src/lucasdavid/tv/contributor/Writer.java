package lucasdavid.tv.contributor;

import org.jetbrains.annotations.NotNull;

/**
 * @author lucasdavid
 */
public class Writer extends Contributor {

    /**
     * Default constructor.
     * Allocates fields with empty values.
     *
     * @see Contributor#Contributor()
     */
    public Writer() {
        super();
    }

    /**
     * Constructor.
     *
     * @param name writer's name
     */
    public Writer(@NotNull String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Writer) {
            return super.equals(obj);
        }
        return false;
    }
}
