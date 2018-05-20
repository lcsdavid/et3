package lucasdavid.tv;

import lucasdavid.xml.element.Element;
import lucasdavid.xml.XMLParser;
import lucasdavid.tv.credits.Contributor;
import lucasdavid.tv.programs.BroadcastedProgram;
import lucasdavid.tv.programs.EnumCSA;
import lucasdavid.tv.programs.Program;
import lucasdavid.xml.element.NotExceptedElementException;
import org.jetbrains.annotations.NotNull;

import javax.xml.stream.XMLStreamException;
import java.io.IOException;
import java.util.*;
import java.util.concurrent.TimeUnit;
import java.util.function.Predicate;

/**
 * Interface-user class.
 * Contains most of all answers as API functionality.
 *
 * @author lucasdavid
 */
public class TV {
    private boolean loaded;

    private List<Channel> channels;
    private List<BroadcastedProgram> programmation;
    private List<Contributor> contributors;

    /**
     * Constructor.
     * Allocates fields with empty values.
     */
    public TV() {
        loaded = false;

        channels = new ArrayList<>();
        programmation = new ArrayList<>();
        contributors = new ArrayList<>();
    }

    /* Get & Set */

    /**
     * Depuis un fichier adapté charge les informations relative au programmes télévisés.
     * Doit être appelé avant tout autre action sur la classe sinon on a aucune donnée sinon une exception sera levée {@link NotLoadedException}.
     *
     * @param tvFile fichier de description de la programmation télévisée
     * @throws NotLoadedException échec dans le chargement des données {@link IOException}, {@link XMLStreamException}
     */
    public void load(@NotNull String tvFile) throws NotLoadedException {
        XMLParser parser = null;
        try {
            parser = new XMLParser(tvFile);
            parser.parse();
        } catch (IOException | XMLStreamException e) {
            e.printStackTrace();
            throw new NotLoadedException("");
        }

        loaded = true;

        parser.queryElementsByName("channel").forEach(element -> {
            try {
                channels.add(new Channel((Element) element));
            } catch (NotExceptedElementException notExceptedElementException) {
                notExceptedElementException.printStackTrace();
            }
        });

        parser.queryElementsByName("programme").forEach(element -> {
            try {
                programmation.add(new BroadcastedProgram((Element) element));
            } catch (NotExceptedElementException notExceptedElementException) {
                notExceptedElementException.printStackTrace();
            }
        });
        bind();
    }

    /**
     * Binds {@link Channel}s with {@link BroadcastedProgram#channel}.
     * Fills {@link TV#contributors} list with
     * {@link TV#programmation}'s {@link BroadcastedProgram#program}'s {@link Program#credits}.
     */
    private void bind() {
        for (BroadcastedProgram broadcastedProgram: programmation) {
            List<Channel> channelQuery = queryChannels(c -> c.equals(broadcastedProgram.getChannel()));
            if(!channelQuery.isEmpty()) { /* On fait rien si y'a rien tanpis. */
                while (channelQuery.size() > 1) { /* Doublon où erreur dans le fichier XML, on retire l'excedant */
                    channels.remove(channelQuery.get(0));
                    channelQuery.remove(0);
                }
                broadcastedProgram.setChannel(channelQuery.get(0));
            }

            List<Contributor> contributors = broadcastedProgram.getProgram().getCredits();
            /* Si la liste est vide c'est regrettable mais c'est plus ma faute */
            this.contributors.addAll(contributors);
        }

    }

    /**
     * Question 1: Liste des chaînes.
     * Returns {@link TV#channels}.
     *
     * @return {@link TV#channels}
     * @throws NotLoadedException If file not loaded, ie. {@code loaded == true}.
     */
    public List<Channel> getChannels() throws NotLoadedException {
        if (!loaded)
            throw new NotLoadedException();
        return channels;
    }

    /**
     * Returns {@link TV#programmation}.
     *
     * @return {@link TV#programmation}
     * @throws NotLoadedException If file not loaded, ie. {@code loaded == true}.
     */
    public List<BroadcastedProgram> getProgrammation() throws NotLoadedException {
        if (!loaded)
            throw new NotLoadedException();
        return programmation;
    }

    /**
     * Returns {@link TV#contributors}.
     *
     * @return {@link TV#contributors}
     * @throws NotLoadedException If file not loaded, ie. {@code loaded == true}.
     */
    public List<Contributor> getContributors() throws NotLoadedException {
        if (!loaded)
            throw new NotLoadedException();
        return contributors;
    }

    /**
     * Clears lists.
     */
    public void clear() {
        channels.clear();
        programmation.clear();
        contributors.clear();
    }

    /* Questions (cas autres) */

    /**
     * Question 2: Liste des jours programmés.
     * Lists all days programmed.
     *
     * @return all days programmed
     * @throws NotLoadedException If file not loaded, ie. {@code loaded == true}.
     */
    public List<Date> daysProgrammed() throws NotLoadedException {
        if (!loaded) throw new NotLoadedException();
        List<Date> result = new ArrayList<>();
        for (BroadcastedProgram p : programmation) {
            Date current_date = new Date(TimeUnit.DAYS.convert(p.getProgramming().getTime(), TimeUnit.MILLISECONDS));
            if (!programmation.stream().findAny().filter(any -> any.getProgramming().equals(current_date)).isPresent())
                result.add(current_date);
        }
        return result;
    }

    /**
     * Question 3: Programmation d'un jour et d'une chaîne donné.
     * Lists all {@link BroadcastedProgram} for a given day and a given channel.
     *
     * @param channel given day
     * @param day     given channel
     * @return all {@link BroadcastedProgram} for a given day and a given channel
     * @throws NotLoadedException If file not loaded, ie. {@code loaded == true}.
     */
    public List<BroadcastedProgram> programmationOfnAt(@NotNull Channel channel, @NotNull Date day) throws NotLoadedException {
        if (!loaded)
            throw new NotLoadedException();
        Predicate<BroadcastedProgram> filter = new Predicate<BroadcastedProgram>() {
            @Override
            public boolean test(BroadcastedProgram program) {
                Date programming = new Date(TimeUnit.DAYS.convert(program.getProgramming().getTime(), TimeUnit.MILLISECONDS));
                day.setTime(TimeUnit.DAYS.convert(day.getTime(), TimeUnit.MILLISECONDS));
                return program.getChannel().getId().equals(channel.getId()) && programming.equals(day);
            }
        };
        return queryPrograms(filter);
    }

    /**
     * Question 5: Liste des émissions pendant un laps de temps donné.
     * Lists {@link BroadcastedProgram} for a given time.
     *
     * @param moment given time
     * @return {@link BroadcastedProgram} for a given time.
     * @throws NotLoadedException If file not loaded, ie. {@code loaded == true}.
     */
    public List<BroadcastedProgram> programsWhile(@NotNull Date moment) throws NotLoadedException {
        if (!loaded)
            throw new NotLoadedException();
        Predicate<BroadcastedProgram> filter = new Predicate<BroadcastedProgram>() {
            @Override
            public boolean test(BroadcastedProgram program) {
                Date start = program.getProgramming();
                Date end = new Date(program.getProgramming().getTime() + program.getProgram().getLenght());
                return moment.after(start) && moment.before(end);
            }
        };
        return queryPrograms(filter);
    }

    /**
     * Question 6: Liste des programmes (pas que film) concernant un contributeur
     * (pas qu'acteur ou réalisateur parce que tant qu'à faire).
     * Lists {@link BroadcastedProgram} which containes a given {@link Contributor}.
     *
     * @param contributor condition
     * @return {@link BroadcastedProgram} which containes a given {@link Contributor}.
     * @throws NotLoadedException If file not loaded, ie. {@code loaded == true}.
     */
    public List<Program> programsWith(@NotNull Contributor contributor) throws NotLoadedException {
        if (!loaded)
            throw new NotLoadedException();
        Predicate<BroadcastedProgram> filter = new Predicate<BroadcastedProgram>() {
            @Override
            public boolean test(BroadcastedProgram program) {
                return program.getProgram().getCredits().removeIf(c -> !contributor.getName().equals(c.getName()));
            }
        };
        List<BroadcastedProgram> query = queryPrograms(filter);
        List<Program> result = new ArrayList<>();
        for (BroadcastedProgram p : query)
            result.add(p.getProgram());
        return result;
    }

    /**
     * Question 9: Nombre de chaque catégorie CSA.
     *
     * @return une {@link Map} catégorie CSA / nombre d'occurence
     * @throws NotLoadedException If file not loaded, ie. {@code loaded == true}.
     */
    public Map<EnumCSA, Integer> enumCSAMultiplicty() throws NotLoadedException {
        if (!loaded)
            throw new NotLoadedException();
        Map<EnumCSA, Integer> result = new HashMap<>();
        for (BroadcastedProgram broadcastedProgram : programmation) {
            EnumCSA enumCSA = broadcastedProgram.getProgram().getRating();
            if (result.containsKey(enumCSA))
                result.put(enumCSA, 0);
            else
                result.put(enumCSA, result.get(enumCSA) + 1);
        }
        return result;
    }


    /**
     * Question 11: Génération XHTML.
     * Generates a XHTML file, which summarize all analysis.
     *
     * @throws NotLoadedException If file not loaded, ie. {@code loaded == true}.
     */
    public void generateXHTLMReport() throws NotLoadedException {
        if (!loaded) throw new NotLoadedException();

    }

    /* Fonctions génériques */

    /**
     * Queries {@link TV#channels} with a given filter.
     *
     * @param filter query test
     * @return {@link TV#channels} with a given filter
     */
    public List<Channel> queryChannels(@NotNull Predicate<Channel> filter) {
        List<Channel> result = new ArrayList<>(channels);
        result.removeIf(filter.negate());
        return result;
    }

    /**
     * Queries {@link TV#programmation} with a given filter.
     *
     * @param filter query test
     * @return {@link TV#programmation} with a given filter
     */
    public List<BroadcastedProgram> queryPrograms(@NotNull Predicate<BroadcastedProgram> filter) {
        List<BroadcastedProgram> result = new ArrayList<>(programmation);
        result.removeIf(filter.negate());
        return result;
    }

    /**
     * Returns a sorted list of {@link TV#channels} with a given comparator.
     *
     * @param comparator comparison test
     * @return a sorted list of {@link TV#channels} with a given comparator.
     */
    public List<Channel> channelsOrderedBy(@NotNull Comparator<Channel> comparator) {
        List<Channel> result = new ArrayList<>(channels);
        result.sort(comparator);
        return result;
    }

    /**
     * Returns a sorted list of {@link TV#programmation} with a given comparator.
     *
     * @param comparator comparison test
     * @return a sorted list of {@link TV#programmation} with a given comparator.
     */
    public List<BroadcastedProgram> programsOrderedBy(@NotNull Comparator<BroadcastedProgram> comparator) {
        List<BroadcastedProgram> result = new ArrayList<>(programmation);
        result.sort(comparator);
        return result;
    }

    /* Inner class */

    /**
     * @see TV#loaded
     * @see TV#load
     */
    private class NotLoadedException extends Exception {
        /**
         * Default constructor.
         *
         * @see Exception
         */
        public NotLoadedException() {
            super();
        }

        /**
         * Constructor.
         *
         * @param message the detail message. The detail message is saved for
         *                later retrieval by the {@link #getMessage()} method.
         * @see Exception
         */
        public NotLoadedException(String message) {
            super(message);
        }
    }
}

