package lucasdavid.tv.contributor;

import org.jetbrains.annotations.NotNull;

/**
 * @author lucasdavid
 */
public class Guest extends Contributor {

    /**
     * Default constructor.
     * Allocates fields with empty values.
     *
     * @see Contributor#Contributor()
     */
    public Guest() {
        super();
    }

    /**
     * Constructor.
     *
     * @param name guest's name
     */
    public Guest(@NotNull String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Guest) {
            return super.equals(obj);
        }
        return false;
    }
}
