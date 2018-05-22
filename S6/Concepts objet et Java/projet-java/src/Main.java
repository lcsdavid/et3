import lucasdavid.tv.Channel;
import lucasdavid.tv.TV;
import lucasdavid.tv.contributor.Contributor;
import lucasdavid.tv.programs.BroadcastedProgram;
import lucasdavid.tv.programs.EnumCSA;
import lucasdavid.tv.programs.Program;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;
import java.util.Map;


/**
 * Main test class.
 *
 * @author lucasdavid
 */
public class Main {

    private static SimpleDateFormat parser = new SimpleDateFormat("dd/MM/yyyy hh:mm:ss");
    private static SimpleDateFormat formatter = new SimpleDateFormat("EEEE dd MMMM yyyy");


    public static void main(String[] args) throws Exception {
        TV tv = new TV();
        /* Nécessaire */
        tv.load("res/tvguide_20180430_20180511.xml");

        /* RAS */
        List<Channel> chaînes = tv.getChannels();
        for (Channel chaîne: chaînes) {
            //System.out.println(chaîne);
        }

        System.out.println();

        /* RAS */
        List<Date> jourProgrammés = tv.daysProgrammed();
        for (Date jour: jourProgrammés) {
            //System.out.println(formatter.format(jour));
        }

        System.out.println();

        /* Remplacer id et jour tester /!\ n'importe quelle heure du jour compte */
        String jour = "11/05/2018 02:00:00";
        Channel chaîne = new Channel("C80.api.telerama.fr", "");
        List<BroadcastedProgram> programmesSurEtLe = tv.programmationOfnAt(chaîne, parser.parse(jour));
        for (BroadcastedProgram program: programmesSurEtLe) {
            //System.out.println(program);
        }

        System.out.println();

        /* Remplacer pour tester /!\ le moment c'est strictement pendant le programme */
        String moment = "11/05/2018 02:32:20";
        List<BroadcastedProgram> programmesPendant = tv.programsWhile(parser.parse(moment));
        for (BroadcastedProgram program: programmesPendant) {
            //System.out.println(program);
        }

        System.out.println();

        /* On peut spécifier via la classe un rôle Acteur ou Présentateur pour affiner les recherches */
        String nomDeContributeur = "Vincent Ferniot"; /* ou Michel Hassan */
        Contributor contributeur = new Contributor(nomDeContributeur);
        List<Program> programmesAvec = tv.programsWith(contributeur);
        for (Program program: programmesAvec) {
            System.out.println(program);
        }

        System.out.println();

        /* RSA */
        Map<EnumCSA, Integer> occurencesDesNormesCSA = tv.CSAOccurrences();
        for (Map.Entry<EnumCSA, Integer> entrée: occurencesDesNormesCSA.entrySet()) {
            //System.out.println(entrée.getKey() + " : " + entrée.getValue() + " occurences.");
        }

        System.out.println();

    }
}
