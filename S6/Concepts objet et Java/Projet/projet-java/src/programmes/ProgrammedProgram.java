package programmes;

import tv.Channel;

import java.util.Date;
import java.util.Formatter;
import java.util.Locale;

public class ProgrammedProgram {
    private Program program;
    private Channel channel;
    private Date programming;
    private boolean previouslyShown;
    private boolean premiere;

    public ProgrammedProgram() {
        program = new Program();
        previouslyShown = false;
    }

    public Program program() {
        return program;
    }

    public void setProgram(Program program) {
        this.program = program;
    }

    public void channel(Channel channel) {
        this.channel = channel;
    }

    public Channel channel() {
        return channel;
    }

    public void setProgramming(Date programming) {
        this.programming = programming;
    }

    public void setPreviouslyShown(boolean previouslyShown) {
        this.previouslyShown = previouslyShown;
    }

    @Override
    public String toString() {
        StringBuilder stringBuilder = new StringBuilder("[ProgrammedProgram\n\t");
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
