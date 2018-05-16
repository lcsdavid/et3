package xml;

import csa.CSARating;
import javafx.util.Pair;
import programmes.*;
import programmes.catégories.*;
import tv.Channel;

import java.io.FileNotFoundException;
import java.io.FileReader;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import javax.xml.stream.XMLInputFactory;
import javax.xml.stream.XMLStreamException;
import javax.xml.stream.XMLStreamReader;
import javax.xml.stream.events.XMLEvent;

public class XMLParser {
    private String file;
    private XMLInputFactory inputFactory;
    private XMLStreamReader streamReader;

    public XMLParser(String file) {
        this.file = file;
        inputFactory = XMLInputFactory.newInstance();
    }

    public List<Channel> parseChannels() throws XMLStreamException {
        try {
            streamReader = inputFactory.createXMLStreamReader(new FileReader(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return new ArrayList<>();
        }
        List<Channel> channelList = new ArrayList<>();
        int eventType;
        while (streamReader.hasNext()) {
            eventType = streamReader.next();
            if (eventType == XMLEvent.START_ELEMENT)
                if (streamReader.getLocalName().equals("channel")) {
                    channelList.add(new Channel());
                    channelList.get(channelList.size() - 1).setId(streamReader.getAttributeValue(0));
                } else if (streamReader.getLocalName().equals("display-name")) {
                    streamReader.next();
                    channelList.get(channelList.size() - 1).setName(streamReader.getText());
                }
        }
        streamReader.close();
        return channelList;
    }

    public List<ProgrammedProgram> parseProgrammations() throws XMLStreamException {
        try {
            streamReader = inputFactory.createXMLStreamReader(new FileReader(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return new ArrayList<>();
        }
        List<ProgrammedProgram> programmations = new ArrayList<>();
        ProgrammedProgram current_program = null;
        int eventType;
        String string;
        while (streamReader.hasNext()) {
            eventType = streamReader.next();
            if (eventType == XMLEvent.START_ELEMENT) {
                switch (streamReader.getLocalName()) {
                    case "programme":
                        current_program = new ProgrammedProgram();
                        programmations.add(current_program);
                        try {
                            current_program.setProgramming(new SimpleDateFormat("YYYYMMddHHmmss", Locale.getDefault()).parse(streamReader.getAttributeValue(0)));
                        } catch (ParseException e) {
                            e.printStackTrace();
                        }
                        current_program.channel(new Channel(streamReader.getAttributeValue(3)));
                        break;
                    case "title":
                        streamReader.next();
                        if (current_program != null)
                            current_program.program().setTitle(streamReader.getText());
                        break;
                    case "sub-title":
                        streamReader.next();
                        if (current_program != null)
                            current_program.program().setSubTitle(streamReader.getText());
                        break;
                    case "desc":
                        string = streamReader.getAttributeValue(0);
                        streamReader.next();
                        if (current_program != null)
                            current_program.program().setDesc(streamReader.getText());
                        break;
                    case "credits":
                        break;
                    case "date":
                        streamReader.next();
                        if (current_program != null) {
                            try {
                                current_program.program().setRelease(new SimpleDateFormat("YYYY", Locale.getDefault()).parse(streamReader.getText()));
                            } catch (ParseException e) {
                                e.printStackTrace();
                            }
                        }
                        break;
                    case "category":
                        streamReader.next();
                        if (current_program != null)
                            switch (streamReader.getText().split(" ")[0]) {
                                case "documentaire":
                                    current_program.setProgram(new Documentary(current_program.program()));
                                    break;
                                case "film":
                                    current_program.setProgram(new Film(current_program.program()));
                                    break;
                                case "journal":
                                    current_program.setProgram(new Journal(current_program.program()));
                                    break;
                                case "série":
                                    current_program.setProgram(new Serie(current_program.program()));
                                    break;
                                case "feuilleton":
                                case "téléfilm":
                                    break;

                                default:
                                    System.getLogger("lol");
                                    break;
                            }
                        break;
                    case "length":
                        string = streamReader.getAttributeValue(0);
                        long length = 0;
                        streamReader.next();
                        switch (string) {
                            case "hours":
                                length = Long.parseLong(streamReader.getText()) * 60 * 60 * 100;
                                break;
                            case "minutes":
                                length = Long.parseLong(streamReader.getText()) * 60 * 100;
                                break;
                        }
                        if (current_program != null)
                            current_program.program().setLenght(length);
                        break;
                    case "country":
                        streamReader.next();
                        if (current_program != null)
                            current_program.program().setCountry(streamReader.getText());
                        break;
                    case "rating":
                        streamReader.next();
                        if (current_program != null)
                            current_program.program().setRating(CSARating.eval(streamReader.getText()));
                        break;
                    case "star-rating":
                        streamReader.next();
                        streamReader.next();
                        streamReader.next();
                        string = streamReader.getText().split("/")[0];
                        if (current_program != null) {
                            if (string == null || string.isEmpty())
                                current_program.program().setStarRating(Float.NEGATIVE_INFINITY);
                            else current_program.program().setStarRating(Float.parseFloat(string));
                        }
                        break;
                    default:
                        break;
                }
            }
        }
        return programmations;
    }

    public Pair<List<Channel>, List<ProgrammedProgram>> parseAll() throws XMLStreamException {
        try {
            streamReader = inputFactory.createXMLStreamReader(new FileReader(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return new Pair<>(new ArrayList<>(), new ArrayList<>());
        }
        List<Channel> channels = parseChannels();
        List<ProgrammedProgram> programations = parseProgrammations();
        for (Channel channel: channels)
            for (ProgrammedProgram program: programations)
                if(channel.id() == program.channel().id())
                    program.channel(channel);
        return new Pair<>(channels, programations);
    }
}
