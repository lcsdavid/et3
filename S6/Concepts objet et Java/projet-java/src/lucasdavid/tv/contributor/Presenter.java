package lucasdavid.tv.contributor;

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

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Presenter) {
            return super.equals(obj);
        }
        return false;
    }
}
