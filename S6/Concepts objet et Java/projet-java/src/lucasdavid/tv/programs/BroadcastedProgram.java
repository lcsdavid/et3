package lucasdavid.tv.programs;

import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

import lucasdavid.xml.element.Element;
import lucasdavid.xml.element.NotExceptedElementException;

import lucasdavid.tv.Channel;
import org.jetbrains.annotations.NotNull;

/**
 * @author lucasdavid
 */
public final class BroadcastedProgram {
    private Program program;
    private Channel channel;
    private Date programming;

    /**
     * Constructor.
     * Extracts data from a given {@link Element}.
     *
     * @param element data container
     * @throws NotExceptedElementException If {@code element} not valid or miss data
     */
    public BroadcastedProgram(@NotNull Element element) throws NotExceptedElementException {
        if(!element.getName().equals("programme"))
            throw new NotExceptedElementException("not \"programme\"");
        program = Program.newInstance(element);

        String start = element.getAttribute("start");
        if(start == null)
            throw new NotExceptedElementException("miss \"start\" attribute");
        try {
            programming = new SimpleDateFormat("YYYYMMddmmss").parse(start);
        } catch (ParseException e) {
            e.printStackTrace();
            throw new NotExceptedElementException("not valid \"start\" attribute");
        }

        String channelId = element.getAttribute("channel");
        if(channelId == null)
            throw new NotExceptedElementException("miss \"channel\" attribute");
        channel = new Channel(channelId, "NaN");
    }

    /* Getters */

    /**
     * Returns {@link BroadcastedProgram#program}.
     *
     * @return {@link BroadcastedProgram#program}
     */
    public Program getProgram() {
        return program;
    }

    /**
     * Returns {@link BroadcastedProgram#channel}.
     *
     * @return {@link BroadcastedProgram#channel}
     */
    public Channel getChannel() {
        return channel;
    }

    /**
     * Sets {@link BroadcastedProgram#channel}.
     *
     * @param channel channel on which the program is broadcasted
     */
    public void setChannel(@NotNull Channel channel) {
        this.channel = channel;
    }

    /**
     * Returns {@link BroadcastedProgram#programming}.
     *
     * @return {@link BroadcastedProgram#programming}
     */
    public Date getProgramming() {
        return programming;
    }

    /**
     * Question 4: Affichage programme adéquat.
     * Returns a partial {@link String} descriptor of {@code this}.
     *
     * @return a partial {@link String} descriptor of {@code this}
     * @see Program
     * @see Channel
     */
    @Override
    public String toString() {
        String s = "[" + getClass().getSimpleName() + ": " + getProgram().getTitle() + '\n';
        s += "on: " + getChannel().getName() + '\n';
        s += "at: " + new SimpleDateFormat("[EEEE d MMMM] hh:mm").format(getProgramming()) + '\n';
        s += ']';
        return s;
    }
}
