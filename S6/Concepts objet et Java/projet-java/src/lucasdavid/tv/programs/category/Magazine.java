package lucasdavid.tv.programs.category;

import lucasdavid.tv.programs.Program;

/**
 * @author lucasdavid
 */
public class Magazine extends Program {

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Magazine) {
            return super.equals(obj);
        }
        return false;
    }
}
