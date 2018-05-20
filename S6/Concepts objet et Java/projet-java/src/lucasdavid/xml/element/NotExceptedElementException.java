package lucasdavid.xml.element;

import org.jetbrains.annotations.NotNull;

/**
 * @author lucasdavid
 */
public class NotExceptedElementException extends Exception {
    /**
     * Default constructor.
     *
     * @see Exception
     */
    public NotExceptedElementException() {
        super();
    }

    /**
     * Constructor.
     *
     * @param message the detail message. The detail message is saved for
     *                later retrieval by the {@link #getMessage()} method.
     * @see Exception
     */
    public NotExceptedElementException(@NotNull String message) {
        super(message);
    }
}
