package lucasdavid.tv.programs.category;

import lucasdavid.tv.programs.Program;

/**
 * @author lucasdavid
 */
public class Serie extends Program {

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Serie) {
            return super.equals(obj);
        }
        return false;
    }
}
