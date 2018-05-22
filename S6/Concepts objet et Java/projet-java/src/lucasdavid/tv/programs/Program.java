package lucasdavid.tv.programs;

import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.Objects;
import java.util.concurrent.TimeUnit;

import lucasdavid.xml.element.AbstractElement;
import lucasdavid.xml.element.Element;
import lucasdavid.xml.element.NotExceptedElementException;
import lucasdavid.xml.element.SimpleElement;

import lucasdavid.tv.contributor.Contributor;
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
     * Sets data from a given {@link Element}.
     *
     * @param element data container
     */
    private void set(@NotNull Element element) throws NotExceptedElementException {
        for (AbstractElement subElement : element.getSubElements()) {
            switch (subElement.getName()) {
                case "title":
                    if (subElement instanceof SimpleElement) {
                        SimpleElement title = (SimpleElement) subElement;
                        this.title = title.getText();
                    } else
                        throw new NotExceptedElementException("not a SimpleElement");
                    break;
                case "sub-title":
                    if (subElement instanceof SimpleElement) {
                        SimpleElement subtitle = (SimpleElement) subElement;
                        this.subtitle = subtitle.getText();
                    } else
                        throw new NotExceptedElementException("not a SimpleElement");
                    break;
                case "desc":
                    if (subElement instanceof SimpleElement) {
                        SimpleElement description = (SimpleElement) subElement;
                        this.description = description.getText();
                    } else
                        throw new NotExceptedElementException("not a SimpleElement");
                    break;
                case "credits":
                    if (subElement instanceof Element) {
                        Element credits = (Element) subElement;
                        this.credits = Contributor.newInstances(credits);
                    } else
                        throw new NotExceptedElementException("not an Element");
                    break;
                case "length":
                    if (subElement instanceof SimpleElement) {
                        if (subElement.hasAttributes()) {
                            SimpleElement lenght = (SimpleElement) subElement;
                            int parse = Integer.parseInt(lenght.getText());
                            if (lenght.getAttribute("units").equals("minutes"))
                                this.lenght = TimeUnit.MINUTES.toMillis(parse);
                            else if (lenght.getAttribute("units").equals("hours"))
                                this.lenght = TimeUnit.HOURS.toMillis(parse);
                        } else
                            throw new NotExceptedElementException("miss attributes");
                    } else
                        throw new NotExceptedElementException("not a SimpleElement");

                    break;
                case "star-rating":
                    if (subElement instanceof Element) {
                        Element starRating = (Element) subElement;
                        SimpleElement starRating_ = (SimpleElement) starRating.getSubElements().get(0);
                        this.starRating = Float.parseFloat(starRating_.getText().split("/")[0]);
                    } else
                        throw new NotExceptedElementException("not an Element \"star-rating\"");
                    break;
                case "rating":
                    if (subElement instanceof Element) {
                        Element rating = (Element) subElement;
                        SimpleElement rating_ = (SimpleElement) rating.getSubElements().get(0);
                        this.rating = EnumCSA.parseEnumCSA(rating_.getText());
                    } else
                        throw new NotExceptedElementException("not an Element \"rating\"");
                    break;
            }
        }
    }

    /**
     * Returns a new instance of {@link Program} and set data from a given {@link Element}.
     *
     * @param element data container
     * @return a new instance of {@link Program} from a given {@link Element},
     * otherwise {@code null} if the {@link Element} can't be queried.
     * @throws NotExceptedElementException ...
     * @see Program#set(Element)
     */
    public static Program newInstance(@NotNull Element element) throws NotExceptedElementException {
        if (!element.getName().equals("programme"))
            throw new NotExceptedElementException("not \"programme\"");

        List<AbstractElement> categories = element.query(e -> e.getName().equals("category"));
        if (categories.isEmpty())
            throw new NotExceptedElementException("miss \"category\"");
        if (categories.size() != 1)
            throw new NotExceptedElementException("excepted 1 \"category\"");
        String category = ((SimpleElement) categories.get(0)).getText().split(" ")[0];
        Program newInstance;
        switch (category) {
            case "documentaire":
                newInstance = new Documentary();
                break;
            case "film":
                newInstance = new Film();
                break;
            case "journal":
                newInstance = new Journal();
                break;
            case "magazine":
                newInstance = new Magazine();
                break;
            case "série":
                newInstance = new Serie();
                break;
            case "téléfilm":
                newInstance = new TVMovie();
                break;
            default:
                newInstance = new Program();
                break;
        }

        newInstance.set(element);
        return newInstance;
    }

    @Override
    public int hashCode() {
        return Objects.hash(getClass(), title, subtitle, lenght);
    }

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Program) {
            Program program = (Program) obj;
            return title.equals(program.title) && subtitle.equals(program.subtitle)
                    && lenght == program.lenght;
        }
        return false;
    }

    /**
     * Question 4: Affichage programme adéquat.
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
     * Question 4: Affichage programme adéquat.
     * Returns a partial {@link String} descriptor of {@code this}.
     * More info than {@link Program#brief()} .
     *
     * @return a partial {@link String} descriptor of {@code this}
     */
    @Override
    public String toString() {
        String s = '[' + getClass().getSimpleName() + ": " + title + '\n';
        if (!subtitle.isEmpty())
            s += subtitle + '\n';
        s += description + ']';
        return s;
    }
}
