package lucasdavid.tv.programs;

import lucasdavid.xml.element.Element;
import lucasdavid.xml.element.NotExceptedElement;
import lucasdavid.tv.Channel;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.*;

public final class BroadcastedProgram {
    private Program program;
    private Channel channel;
    private Date programming;

    public BroadcastedProgram(Element element) throws NotExceptedElement {
        try {
            SimpleDateFormat simpleDateFormat = new SimpleDateFormat();
            programming = simpleDateFormat.parse("YYYY");
        } catch (ParseException e) {
            programming = new Date(0);
            e.printStackTrace();
        }
        program = Program.newInstance(element);
    }

    /* Getter */
    public Program getProgram() {
        return program;
    }
    public Channel getChannel() {
        return channel;
    }
    public Date getProgramming() {
        return programming;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder("[BroadcastedProgram\n\t");
        for (String str : program.toString().split("\n")) stringBuilder.append(str).append("\n\t");
        for (String str : channel.toString().split("\n")) stringBuilder.append(str).append("\n\t");
        stringBuilder.append("Programmation: ");
        Formatter formatter = new Formatter(Locale.getDefault());
        long time = programming.getTime();
        formatter.format("%tA ", time).format("%td ", time).format("%tB", time).format(" %tk", time).format(":%tM", time);
        stringBuilder.append(formatter.toString()).append("\n]");
        return stringBuilder.toString();
    }
}
