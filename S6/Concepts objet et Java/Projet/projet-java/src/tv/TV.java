package tv;

import crédits.Intervenant;
import programmes.Program;
import programmes.ProgramField;
import programmes.ProgrammedProgram;
import xml.XMLParser;

import javax.xml.stream.XMLStreamException;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.*;

public class TV {
    private List<Channel> channels;
    private Map<Intervenant, Integer> intervenants;
    private List<ProgrammedProgram> programmations;

    public TV() {
    }

    public TV(List<Channel> list, Map<Intervenant, Integer> map, List<ProgrammedProgram> list_) {
        channels = list;
        intervenants = map;
        programmations = list_;
    }

    public void setup() {
        XMLParser xmlParser = new XMLParser("tvguide_20180430_20180511.xml");
        try {
            xmlParser.parseAll();
        } catch (XMLStreamException e) {
            e.printStackTrace();
        }
    }

    public List<Channel> channels() {
        return channels;
    }

    public void setupChannels() {
        XMLParser xmlParser = new XMLParser("tvguide_20180430_20180511.xml");
        try {
            xmlParser.parseChannels();
        } catch (XMLStreamException e) {
            e.printStackTrace();
        }
    }

    public Map<Intervenant, Integer> intervenants() {
        return intervenants;
    }

    public void setupIntevenants() {
        setupProgrammations();
    }

    public List<ProgrammedProgram> programmations() {
        return programmations;
    }

    public void setupProgrammations() {
        XMLParser xmlParser = new XMLParser("tvguide_20180430_20180511.xml");
        try {
            programmations = xmlParser.parseProgrammations();
        } catch (XMLStreamException e) {
            e.printStackTrace();
        }
    }

    public List<Intervenant> intervenantsOrderedBy() {
        List<Map.Entry<Intervenant, Integer>> listII = new ArrayList<>(intervenants.entrySet());
        listII.sort(Map.Entry.comparingByValue());
        List<Intervenant> listI = new ArrayList<>();
        for (Map.Entry<Intervenant, Integer> entry : listII) {
            listI.add(entry.getKey());
        }
        return listI;
    }

    public List<Program> programsClassedBy(ProgramField programField) {
        List<Program> programs = new ArrayList<>();
        for (ProgrammedProgram programmation : programmations) programs.add(programmation.program());
        Comparator<Program> comparator = null;
        switch (programField) {
            case TITLE:
                break;

            default:
                break;
        }
        return new ArrayList<>(programs);
    }
}


