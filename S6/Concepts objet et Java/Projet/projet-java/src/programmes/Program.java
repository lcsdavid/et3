package programmes;

import crédits.Intervenant;
import csa.CSARating;

import java.util.*;

public class Program {
    private String title, sub_title, desc;
    private List<Intervenant> credits;
    private Date release;
    private long lenght;
    private String country;
    private float star_rating;
    private CSARating rating;


    public Program() {
        credits = new ArrayList<>();
    }

    public Program(Program program) {
        title = String.valueOf(program.title);
        sub_title = String.valueOf(program.sub_title);
        desc = String.valueOf(program.desc);
        credits = new ArrayList<>(program.credits);
        if (program.release != null)
            release = (Date) program.release.clone();
        lenght = program.lenght;
        country = String.valueOf(program.country);
        star_rating = program.star_rating;
        rating = program.rating;
    }

    public String title() {
        return title;
    }

    public String subbtitle() { return sub_title; }

    public void setTitle(String title) {
        this.title = title;
    }

    public void setSubTitle(String sub_title) {
        this.sub_title = sub_title;
    }

    public void setDesc(String desc) {
        this.desc = desc;
    }

    public void setCredits(List<Intervenant> credits) {
        this.credits = credits;
    }

    public void setRelease(Date release) {
        this.release = release;
    }

    public void setLenght(long lenght) {
        this.lenght = lenght;
    }

    public void setCountry(String country) {
        this.country = country;
    }

    public void setStarRating(float star_rating) {
        this.star_rating = star_rating;
    }

    public void setRating(CSARating rating) {
        this.rating = rating;
    }

    @Override
    protected Object clone() throws CloneNotSupportedException {
        Program p = null;
        try {
            p = (Program) super.clone();
            p.title = String.valueOf(title);
            p.sub_title = String.valueOf(sub_title);
            p.desc = String.valueOf(desc);
            p.credits = new ArrayList<>(credits);
            if (release == null) p.release = null;
            else p.release = (Date) release.clone();
            p.lenght = lenght;
            p.country = String.valueOf(country);
            p.star_rating = star_rating;
            p.rating = rating;
        } catch (CloneNotSupportedException ignored) {}
        return p;
    }

    @Override
    public String toString() {
        StringBuilder s = new StringBuilder("[Programm: ");
        if (getClass() != Program.class) s.append(getClass().getSimpleName());
        s.append("\n\ttitlte = ");
        if (title == null) s.append("undefined");
        else s.append(title);
        s.append("\n\tsub-title = ");
        if (sub_title == null) s.append("undefined");
        else s.append(sub_title);
        s.append("\n\tdesc = ");
        if (desc == null) s.append("undefined");
        else s.append(desc);
        if (!credits.isEmpty()) {
            s.append("\t[Credits:\n");
            for (Intervenant i : credits) {
                s.append("\t\t");
                if (i != null)
                    s.append(" ").append(i);
                s.append("\n");
            }
            s.append("\t]");
        }
        s.append("\t\n\trelease = ");
        if (release == null) s.append("undefined");
        else s.append(release.toString());
        Formatter f = new Formatter();
        f.format("%tk", lenght).format(":%tM", lenght).format(":%tS", lenght);
        s.append("\n\tlenght = ").append(f.toString()).append("\n\tcountry = ");
        if (country == null) s.append("undefined");
        else s.append(country);
        s.append("\n\tstar-rating = ");
        if (star_rating == Float.MAX_VALUE) s.append("undefined");
        else s.append(star_rating);
        s.append("\n\trating = ").append(rating).append("\n]");
        return s.toString();
    }
}
