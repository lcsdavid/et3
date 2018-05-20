package lucasdavid.tv.programs;

public enum EnumCSA {
    NaN, Tout_public;


    public static EnumCSA parseEnumCSA(String string) {
        switch (string) {
            case "Tout public\n":
                return Tout_public;
            default:
                return NaN;
        }
    }


}

