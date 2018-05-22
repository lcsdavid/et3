package lucasdavid.tv.contributor;

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

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Actor) {
            return super.equals(obj);
        }
        return false;
    }
}
