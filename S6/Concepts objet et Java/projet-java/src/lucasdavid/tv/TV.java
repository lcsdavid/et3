package lucasdavid.tv;

import lucasdavid.xml.element.Element;
import lucasdavid.xml.XMLParser;
import lucasdavid.tv.credits.Contributor;
import lucasdavid.tv.programs.BroadcastedProgram;
import lucasdavid.tv.programs.EnumCSA;
import lucasdavid.tv.programs.Program;

import javax.xml.stream.XMLStreamException;
import java.io.IOException;
import java.util.*;
import java.util.concurrent.TimeUnit;
import java.util.function.Predicate;

/**
 * Classe inteface-utilisateur qui réunit la majorité des fonctions de l'énoncé.
 */
public class TV {
    private boolean loaded;

    private List<Channel> channels;
    private List<BroadcastedProgram> programmation;
    private List<Contributor> contributors;

    /**
     * Constructeur.
     * Initialise les listes qui ont pour but de stocker les chaînes, la programmation et les contributeurs.
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
    public void load(String tvFile) throws NotLoadedException {
        XMLParser parser = null;
        try {
            parser = new XMLParser(tvFile);
            parser.parse();
        } catch (IOException | XMLStreamException e) {
            e.printStackTrace();
            throw new NotLoadedException();
        }
        loaded = true;
        parser.queryElementsByName("channel").forEach(element -> {
            channels.add(new Channel((Element) element));
        });
        parser.queryElementsByName("programme").forEach(element -> {
            programmation.add(new BroadcastedProgram((Element) element));
        });
        bind();
    }

    /**
     * Met en relation certaines classes associés programme-chaîne et programme-contributeurs.
     */
    private void bind() {

    }

    /**
     * Question 1: Liste des chaînes.
     *
     * @return {@link List} contenant toutes les chaînes chargées {@link TV#load}
     * @throws NotLoadedException fichier non chargé, chargé le fichier au préalable
     */
    public List<Channel> getChannels() throws NotLoadedException {
        if (!loaded) throw new NotLoadedException();
        return channels;
    }

    /**
     * Accèsseur à la programmation.
     *
     * @return {@link List} contenant toutes les émissions programmées chargées {@link TV#load}
     * @throws NotLoadedException fichier non chargé, chargé le fichier au préalable
     */
    public List<BroadcastedProgram> getProgrammation() throws NotLoadedException {
        if (!loaded) throw new NotLoadedException();
        return programmation;
    }

    /**
     * Vide le contenu chargé en vue d'un autre chargement.
     */
    public void clear() {
        channels.clear();
        programmation.clear();
        contributors.clear();
    }

    /* Questions (cas autres) */

    /**
     * Question 2: Liste des jours programmés.
     *
     * @return {@link List} contenant les jours programmés
     * @throws NotLoadedException fichier non chargé, chargé le fichier au préalable
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
     *
     * @param channel chaîne selectionnée
     * @param day     jour selectionné
     * @return {@link List} contenant la programmation d'un jour et d'une chaîne donné
     * @throws NotLoadedException fichier non chargé, chargé le fichier au préalable
     */
    public List<BroadcastedProgram> programmationOfnAt(Channel channel, Date day) throws NotLoadedException {
        if (!loaded) throw new NotLoadedException();
        assert channel != null && day != null;
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
     *
     * @param moment point dans le tempts sélectionné
     * @return la {@link List} contenant les émissions passant pendant un laps de temps donné
     * @throws NotLoadedException fichier non chargé, chargé le fichier au préalable
     */
    public List<BroadcastedProgram> programsWhile(Date moment) throws NotLoadedException {
        if (!loaded) throw new NotLoadedException();
        assert moment != null;
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
     * Question 6: Liste des programmes (pas que film) concernant un contributeur (pas qu'acteur ou réalisateur parce que tant qu'à faire).
     *
     * @param contributorName nom du contributeur @Not
     * @return la {@link List} contenant les programmes concernant le contributeur donné
     * @throws NotLoadedException fichier non chargé, chargé le fichier au préalable
     */
    public List<Program> programsWith(String contributorName) throws NotLoadedException {
        if (!loaded) throw new NotLoadedException();
        assert contributorName != null;
        if (contributorName.isEmpty())
            return List.of();
        Predicate<BroadcastedProgram> filter = new Predicate<BroadcastedProgram>() {
            @Override
            public boolean test(BroadcastedProgram program) {
                return program.getProgram().getCredits().removeIf(c -> c.getName().equals(contributorName));
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
     * @throws NotLoadedException fichier non chargé, chargé le fichier au préalable
     */
    public Map<EnumCSA, Integer> enumCSAMultiplicty() throws NotLoadedException {
        if (!loaded) throw new NotLoadedException();
        Map<EnumCSA, Integer> result = new HashMap<>();
        return result;
    }


    /**
     * Génère un compte rendu suivant les questions de l'énoncéµ.
     *
     * @throws NotLoadedException fichier non chargé, chargé le fichier au préalable
     */
    public void generateXHTLMReport() throws NotLoadedException {
        if (!loaded) throw new NotLoadedException();

    }

    /* Fonctions génériques */

    public List<Channel> queryChannels(Predicate<Channel> filter) {
        assert filter != null;
        List<Channel> result = new ArrayList<>(channels);
        result.removeIf(filter.negate());
        return result;
    }

    public List<BroadcastedProgram> queryPrograms(Predicate<BroadcastedProgram> filter) {
        assert filter != null;
        List<BroadcastedProgram> result = new ArrayList<>(programmation);
        result.removeIf(filter.negate());
        return result;
    }

    public List<Channel> channelsOrderedBy(Comparator<Channel> comparator) {
        assert comparator != null;
        List<Channel> result = new ArrayList<>(channels);
        result.sort(comparator);
        return result;
    }

    public List<BroadcastedProgram> programsOrderedBy(Comparator<BroadcastedProgram> comparator) {
        assert comparator != null;
        List<BroadcastedProgram> result = new ArrayList<>(programmation);
        result.sort(comparator);
        return result;
    }

    /**
     * @see TV#loaded
     * @see TV#load
     */
    private class NotLoadedException extends Exception {

    }
}

