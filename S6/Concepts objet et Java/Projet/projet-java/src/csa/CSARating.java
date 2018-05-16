package csa;

public enum CSARating {
    undefined, tout_public;

    public static CSARating eval(String string) {
        CSARating csaRating = undefined;
        switch (string) {
            case "Tout public\n":
                csaRating = tout_public;
                break;
            default:
                break;
        }
        return csaRating;
    }

}

