package lucasdavid.tv.programs.category;

import lucasdavid.tv.programs.Program;

/**
 * @author lucasdavid
 */
public class TVMovie extends Program {

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof TVMovie) {
            return super.equals(obj);
        }
        return false;
    }
}
