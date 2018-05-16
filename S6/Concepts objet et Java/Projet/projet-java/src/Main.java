import programmes.ProgrammedProgram;
import xml.XMLParser;
import tv.Channel;

import javax.xml.stream.XMLStreamException;
import java.io.FileNotFoundException;
import java.text.ParseException;
import java.util.BitSet;
import java.util.List;

public class Main {

    public static void main(String[] args) {
        System.out.println("Hello World!");
        BitSet set = new BitSet();
        set.set(4);
        set.set(5);
        BitSet set2 = new BitSet();
        set2.set(10);
        set2.set(8);
        System.out.println(set);
        set.andNot(set2);
        System.out.println(set2);

    }

}
