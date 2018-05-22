package lucasdavid.tv.contributor;

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

    @Override
    public boolean equals(Object obj) {
        if(obj instanceof Writer) {
            return super.equals(obj);
        }
        return false;
    }
}
