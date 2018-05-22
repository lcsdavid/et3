package lucasdavid.tv.programs.category;

import lucasdavid.tv.programs.Program;

/**
 * @author lucasdavid
 */
public class Journal extends Program {

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Journal) {
            return super.equals(obj);
        }
        return false;
    }
}
