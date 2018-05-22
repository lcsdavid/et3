package lucasdavid.tv.programs.category;

import lucasdavid.tv.programs.Program;

/**
 * @author lucasdavid
 */
public class Documentary extends Program {

    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Documentary) {
            return super.equals(obj);
        }
        return false;
    }
}
