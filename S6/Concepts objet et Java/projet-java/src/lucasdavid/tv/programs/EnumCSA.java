package lucasdavid.tv.programs;

import org.jetbrains.annotations.NotNull;

/**
 * @author lucasdavid
 */
public enum EnumCSA {
    NaN, Tout_public;

    /**
     * Parses a {@link String} in a correspondent {@link EnumCSA}.
     * If given string is not recognized, return {@link EnumCSA#NaN}.
     *
     * @param string to be parsed
     * @return a correspondent {@link EnumCSA}
     * Otherwise, if given string is not recognized {@link EnumCSA#NaN}
     */
    public static EnumCSA parseEnumCSA(@NotNull String string) {
        switch (string) {
            case "Tout public\n":
                return Tout_public;
            default:
                return NaN;
        }
    }


}

