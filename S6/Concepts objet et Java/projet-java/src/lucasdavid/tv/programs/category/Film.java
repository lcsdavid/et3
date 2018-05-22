package lucasdavid.tv.programs.category;

import lucasdavid.tv.programs.Program;

import java.util.concurrent.Flow;

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
