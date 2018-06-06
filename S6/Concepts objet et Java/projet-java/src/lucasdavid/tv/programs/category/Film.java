package lucasdavid.tv.programs.category;

import lucasdavid.tv.programs.Program;

/**
 * @author lucasdavid
 */
public class Film extends Program {

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Film) {
            return super.equals(obj);
        }
        return false;
    }
}
