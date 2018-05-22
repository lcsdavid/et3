package lucasdavid.tv.contributor;

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

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Guest) {
            return super.equals(obj);
        }
        return false;
    }
}
