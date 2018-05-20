package lucasdavid.tv.programs;

import lucasdavid.xml.element.AbstractElement;
import lucasdavid.xml.element.Element;
import lucasdavid.xml.element.NotExceptedElement;
import lucasdavid.xml.element.SimpleElement;
import org.jetbrains.annotations.NotNull;
import lucasdavid.tv.credits.Contributor;
import lucasdavid.tv.programs.category.*;

import java.util.*;

/**
 * @author lucasdavid
 */
public class Program {
    private String title;
    private String subTitle;
    private String desc;
    private List<Contributor> credits;
    private Date release;
    private long lenght;
    private String country;
    private float starRating;
    private EnumCSA rating;

    /**
     * Default constructor.
     * Allocates fields with empty values.
     */
    public Program() {
        title = subTitle = desc = country = "";
        credits = new ArrayList<>();
        release = new Date();
    }

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
                    subTitle = ((SimpleElement) subElem).getText();
                    break;
                case "desc":
                    desc = ((SimpleElement) subElem).getText();
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
    public static Program newInstance(@NotNull Element element) throws NotExceptedElement {
        if(!element.getName().equals("programme"))
            throw new NotExceptedElement();
        Program newInstance;
        String category = "";
        for(AbstractElement e: element.getSubElements())
            if(e.getName().equals("categorie"))
                category = ((SimpleElement) e).toString();
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

    /* Getters */
    public String getTitle() {
        return title;
    }
    public String getSubTitle() {
        return subTitle;
    }
    public String getDesc() {
        return desc;
    }
    public List<Contributor> getCredits() {
        return credits;
    }
    public Date getRelease() {
        return release;
    }
    public long getLenght() {
        return lenght;
    }
    public String getCountry() {
        return country;
    }
    public float getStarRating() {
        return starRating;
    }
    public EnumCSA getRating() {
        return rating;
    }

    /**
     * Returns a brief of {@link Program}.
     *
     * @return a brief of {@link Program}.
     */
    public String brief() {
        String s = '[' + getClass().getSimpleName() + ": ";
        if(title.length() > 16)
            s += title.substring(0, 13) + "...";
        else
            s += title;
        s += '\n';
        if(desc.length() > 25)
            s += desc.substring(0, 22) + "...";
        else
            s += desc;
        s += ']';
        return s;
    }

    /**
     * Returns a partial {@link String} descriptor of {@link Program}.
     * More info than {@link Program#brief()} .
     *
     * @return a partial {@link String} descriptor of {@link Program}.
     */
    @Override
    public String toString() {
        String s = '[' + getClass().getSimpleName() + ": " + title + '\n';
        s += subTitle + '\n';
        s += desc + "\n]";
        return s;
    }
}
