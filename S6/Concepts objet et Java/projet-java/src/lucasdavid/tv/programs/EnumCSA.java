package lucasdavid.tv.programs;

import org.jetbrains.annotations.NotNull;

/**
 * @author lucasdavid
 */
public enum EnumCSA {
    NaN, Tout_public, Moins_10, Moins_12, Moins_16, Moins_18;

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
            case "Tout public":
                return Tout_public;
            case "-10":
                return Moins_10;
            case "-12":
                return Moins_12;
            case "-16":
                return Moins_16;
            case "-18":
                return Moins_18;
            default:
                return NaN;
        }
    }

    @Override
    public String toString() {
        switch (this) {
            case Tout_public:
                return "Tout public";
            case Moins_10:
                return "-10";
            case Moins_12:
                return "-12";
            case Moins_16:
                return "-16";
            case Moins_18:
                return "-18";
            default:
                return "NaN";
        }
    }
}

