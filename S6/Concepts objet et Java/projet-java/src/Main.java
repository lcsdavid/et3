import lucasdavid.tv.TV;
import lucasdavid.tv.contributor.*;
import lucasdavid.tv.programs.BroadcastedProgram;

import java.io.File;
import java.nio.charset.StandardCharsets;
import java.text.SimpleDateFormat;
import java.util.*;
import java.util.jar.JarFile;


/**
 * Main test class.
 *
 * @author lucasdavid
 */
public class Main {
    private static Scanner in = new Scanner(System.in);
    private static SimpleDateFormat parser = new SimpleDateFormat("dd/MM/yyyy HH:mm:ss");
    private static SimpleDateFormat formatter = new SimpleDateFormat("EEEE dd MMMM yyyy");
    private static SimpleDateFormat formatter_ = new SimpleDateFormat("EEEE dd MMMM yyyy HH:mm:ss");

    public static void main(String[] args) throws Exception {
        TV tv = new TV();
        /* Nécessaire */
        tv.load(Main.class.getClassLoader().getResourceAsStream("tvguide_20180430_20180511.xml"));

        System.in.skip(8);

        System.out.println("[1] : liste des chaînes.");
        System.out.println("[2] : jours programmés.");
        System.out.println("[3] : programmes sur [chaîne] et le [date].");
        System.out.println("[4] : programmes pendant [date].");
        System.out.println("[5] : programmes avec [contributeur].");
        System.out.println("[6] : palmares des contributeurs.");
        System.out.println("[7] : ocurrences des catégories de programme.");
        System.out.println("[8] : ocurrences des évaluations CSA des programmes.");
        System.out.println("[9] : recherche par mots-clés.");
        System.out.println();

        char c = (char) System.in.read();
        System.in.skip(8);
        System.out.println();

        switch (c) {
            case '1':
                tv.getChannels().forEach(System.out::println);
                break;
            case '2':
                /*.sort(Date::compareTo)*/
                tv.daysProgrammed().forEach(System.out::println);
                break;
            case '3':
                System.out.println("Choisir chaîne: ");
                for(int index = 0; index < tv.getChannels().size(); index++)
                    System.out.println("[" + (index  + 1) + "] : " + tv.getChannels().get(index).getName());
                System.out.println();

                byte[] i = new byte[2];
                System.in.read(i);
                System.in.skip(8);
                System.out.println();

                int index = (Byte.toUnsignedInt(i[0]) - '0') * 10 + Byte.toUnsignedInt(i[1]) - '1';

                if(index > tv.getChannels().size()) {
                    System.out.println("Entrée pas valide.");
                    System.exit(0);
                }


                Date jour = parser.parse("11/05/2018 02:32:20");
                boolean loop = true;
                while(loop) {
                    System.out.print("\rUse - and + : " + formatter.format(jour) + "  ");
                    c = (char) System.in.read();
                    System.in.skip(8);
                    switch (c) {
                        case '+':
                            jour.setTime(jour.getTime() + 86400000);
                            break;
                        case '-':
                            jour.setTime(jour.getTime() - 86400000);
                            break;
                        default:
                            loop = false;
                            break;
                    }
                }
                tv.programmationOfnAt(tv.getChannels().get(index), jour).forEach(System.out::println);
                break;
            case '4':
                Date moment = parser.parse("11/05/2018 02:32:20");
                boolean loop_ = true;
                while(loop_) {
                    System.out.print("\rUse - and + : " + formatter_.format(moment) + "  ");
                    c = (char) System.in.read();
                    System.in.skip(8);
                    switch (c) {
                        case '+':
                            moment.setTime(moment.getTime() + 60000);
                            break;
                        case '-':
                            moment.setTime(moment.getTime() - 60000);
                            break;
                        default:
                            loop_ = false;
                            break;
                    }
                }
                List<BroadcastedProgram> programsWhile = tv.programsWhile(moment);
                programsWhile.sort(Comparator.comparing(BroadcastedProgram::getProgramming));
                programsWhile.forEach(System.out::println);
                break;
            case '5':
                System.out.println("[1] : Acteur");
                System.out.println("[2] : Contributeur (classe parente)");
                System.out.println("[3] : Directeur");
                System.out.println("[4] : Invité");
                System.out.println("[5] : Présentateur");
                System.out.println("[6] : Scripteur");
                System.out.println();

                c = (char) System.in.read();
                System.in.skip(8);
                System.out.println();

                System.out.println("Choisir le nom: ");
                byte[] b = new byte[32];
                System.in.read(b);
                String s = new String(b, StandardCharsets.UTF_8);
                System.out.println();

                /* On peut spécifier via la classe un rôle Acteur ou Présentateur pour affiner les recherches */
                Contributor contributor = null;
                switch (c) {
                    case '1':
                        contributor = new Actor(s);
                        break;
                    case '2':
                        contributor = new Contributor(s);
                        break;
                    case '3':
                        contributor = new Director(s);
                        break;
                    case '4':
                        contributor = new Guest(s);
                        break;
                    case '5':
                        contributor = new Presenter(s);
                        break;
                    case '6':
                        contributor = new Writer(s);
                        break;
                    default:
                        System.out.println("Erreur.");
                        System.exit(1);
                        break;
                }
                tv.programsWith(contributor);
                break;
            case '6':
                tv.palmares().forEach((key, value) -> System.out.println(key + ": " + value));
                break;
            case '7':
                tv.categoryOccurrences().forEach((key, value) -> System.out.println(key + ": " + value));
                break;
            case '8':
                tv.CSAOccurrences().forEach((key, value) -> System.out.println(key + ": " + value));
                break;
            case '9':
                tv.keyWordSearch(System.console().readLine()).forEach(System.out::println);
                break;
            default:
                System.out.println("Erreur");
                System.exit(1);
                break;
        }
    }
}
