package lucasdavid.tv.programs;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;

import lucasdavid.xml.element.AbstractElement;
import lucasdavid.xml.element.Element;
import lucasdavid.xml.element.NotExceptedElementException;
import lucasdavid.xml.element.SimpleElement;

import lucasdavid.tv.credits.Contributor;
import lucasdavid.tv.programs.category.*;

import org.jetbrains.annotations.NotNull;


/**
 * @author lucasdavid
 */
public class Program {
    private String title;
    private String subtitle;
    private String description;
    private List<Contributor> credits;
    private Date release;

    /**
     * Time in millisecondes.
     */
    private long lenght;
    private String country;
    private float starRating;
    private EnumCSA rating;

    /**
     * Default constructor.
     * Allocates fields with empty values.
     */
    public Program() {
        title = subtitle = description = "";
        credits = new ArrayList<>();
        release = new Date();
        lenght = 0;
        country = "";
        rating = EnumCSA.NaN;
    }

    /* Getters */

    /**
     * Returns {@link Program#title}.
     *
     * @return {@link Program#title}.
     */
    public String getTitle() {
        return title;
    }

    /**
     * Returns {@link Program#subtitle}.
     *
     * @return {@link Program#subtitle}.
     */
    public String getSubtitle() {
        return subtitle;
    }

    /**
     * Returns {@link Program#description}.
     *
     * @return {@link Program#description}.
     */
    public String getDescription() {
        return description;
    }

    /**
     * Returns {@link Program#credits}.
     *
     * @return {@link Program#credits}.
     */
    public List<Contributor> getCredits() {
        return credits;
    }

    /**
     * Returns {@link Program#release}.
     *
     * @return {@link Program#release}.
     */
    public Date getRelease() {
        return release;
    }

    /**
     * Returns {@link Program#lenght}.
     *
     * @return {@link Program#lenght}.
     */
    public long getLenght() {
        return lenght;
    }

    /**
     * Returns {@link Program#country}.
     *
     * @return {@link Program#country}.
     */
    public String getCountry() {
        return country;
    }

    /**
     * Returns {@link Program#starRating}.
     *
     * @return {@link Program#starRating}.
     */
    public float getStarRating() {
        return starRating;
    }

    /**
     * Returns {@link Program#rating}.
     *
     * @return {@link Program#rating}.
     */
    public EnumCSA getRating() {
        return rating;
    }

    /* Setter */

    /**
     * Set data from a given {@link Element}.
     *
     * @param element data container
     */
    private void set(@NotNull Element element) {
        element.getSubElements().forEach(subElem -> {
            switch (subElem.getName()) {
                case "title":
                    title = ((SimpleElement) subElem).getText();
                    break;
                case "sub-title":
                    subtitle = ((SimpleElement) subElem).getText();
                    break;
                case "description":
                    description = ((SimpleElement) subElem).getText();
                    break;
                case "lenght":
                    if (subElem.getAttribute("units").equals("minutes"))
                        lenght = Long.parseLong(((SimpleElement) subElem).getText()) * 60000;
                    else if (subElem.getAttribute("units").equals("hours"))
                        lenght = Long.parseLong(((SimpleElement) subElem).getText()) * 36000000;
                    break;
                case "star-rating":
                    starRating = Float.parseFloat(((SimpleElement) subElem).getText());
                    break;
                case "rating":
                    rating = EnumCSA.parseEnumCSA(((SimpleElement) subElem).getText());
                    break;
            }
        });
    }

    /**
     * Returns a new allocated instance of {@link Program} and set data from a given {@link Element},
     * otherwise {@code null} if the {@link Element} can't be queried.
     *
     * @param element data container
     * @return a new allocated instance of {@link Program} from a given {@link Element},
     * otherwise {@code null} if the {@link Element} can't be queried.
     * @see Program#set(Element)
     */
    public static Program newInstance(@NotNull Element element) throws NotExceptedElementException {
        if (!element.getName().equals("programme"))
            throw new NotExceptedElementException("not \"programme\"");

        List<AbstractElement> categories = element.query(e -> e.getName().equals("categorie"));
        if(categories.isEmpty())
            throw new NotExceptedElementException("miss \"categorie\"");
        if(categories.size() != 1)
            throw new NotExceptedElementException("excepted 1 \"categorie\"");
        String category = ((SimpleElement) categories.get(0)).getText();

        Program newInstance;
        switch (category) {
            case "documentaire":
                newInstance = new Documentary();
            case "film":
                newInstance = new Film();
            case "journal":
                newInstance = new Journal();
            case "magazine":
                newInstance = new Magazine();
            case "série":
                newInstance = new Serie();
            case "téléfilm":
                newInstance = new TVMovie();
            default:
                newInstance = new Program();
        }
        newInstance.set(element);
        return newInstance;
    }


    /**
     * Returns a brief of {@code this}.
     *
     * @return a brief of {@code this}
     */
    public String brief() {
        String s = '[' + getClass().getSimpleName() + ": ";
        if (title.length() > 16)
            s += title.substring(0, 13) + "...";
        else
            s += title;
        s += '\n';
        if (description.length() > 25)
            s += description.substring(0, 22) + "...";
        else
            s += description;
        s += ']';
        return s;
    }

    /**
     * Returns a partial {@link String} descriptor of {@code this}.
     * More info than {@link Program#brief()} .
     *
     * @return a partial {@link String} descriptor of {@code this}
     */
    @Override
    public String toString() {
        String s = '[' + getClass().getSimpleName() + ": " + title + '\n';
        s += subtitle + '\n';
        s += description + "\n]";
        return s;
    }
}
