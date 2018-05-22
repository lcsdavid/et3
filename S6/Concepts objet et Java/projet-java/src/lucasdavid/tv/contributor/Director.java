package lucasdavid.tv.contributor;

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

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Director) {
            return super.equals(obj);
        }
        return false;
    }
}
