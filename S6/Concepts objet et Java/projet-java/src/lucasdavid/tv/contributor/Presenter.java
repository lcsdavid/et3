package lucasdavid.tv.contributor;

import org.jetbrains.annotations.NotNull;

/**
 * @author lucasdavid
 */
public class Presenter extends Contributor {

    /**
     * Default constructor.
     * Allocates fields with empty values.
     *
     * @see Contributor#Contributor()
     */
    public Presenter() {
        super();
    }

    /**
     * Constructor.
     *
     * @param name presenter's name
     */
    public Presenter(@NotNull String name) {
        this.name = name;
    }

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Presenter) {
            return super.equals(obj);
        }
        return false;
    }
}
