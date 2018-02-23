package com.fêteforraine;

public class Autotamponneuse {
    public static final float TAILLE = 1.5f;

    private static int nombreAutotamponneuse = 0;

    private int id;
    private boolean surPiste;
    private float X, Y;
    private boolean occupée;
    private String occupant;

    private boolean allumée;
    private boolean clignotante;

    public Autotamponneuse() {
        id = nombreAutotamponneuse + 1;
        nombreAutotamponneuse++;
        surPiste = false;
        X = Y = 0.f;
        occupée = false;
        occupant = "undefined";
        allumée = false;
        clignotante = false;
    }

    public Autotamponneuse(float X, float Y) {
        this();
        if (X > 0 || Y > 0) {
            this.X = X;
            this.Y = Y;
            surPiste = true;
        }
    }

    public double distance(Autotamponneuse autreAutotamponneuse) {
        if(autreAutotamponneuse == null)
            return Double.MAX_VALUE;
        return Math.sqrt(Math.pow(X - autreAutotamponneuse.X, 2)
                + Math.pow(Y - autreAutotamponneuse.Y, 2));
    }

    public static double distance(Autotamponneuse autotamponneuse, Autotamponneuse autotamponneuse_bis) {
        if(autotamponneuse == null || autotamponneuse_bis == null)
            return Double.MAX_VALUE;
        return autotamponneuse.distance(autotamponneuse_bis);
    }

    public boolean collision(Autotamponneuse autreAutotamponneuse) {
        if(autreAutotamponneuse == null)
            return false;
        return TAILLE - distance(autreAutotamponneuse) > 0;
    }

    public static boolean collision(Autotamponneuse autotamponneuse, Autotamponneuse autotamponneuse_bis) {
        if(autotamponneuse == null || autotamponneuse_bis == null)
            return false;
        return autotamponneuse.collision(autotamponneuse_bis);
    }

    public boolean placer(float X, float Y) {
        if(X < 0 || Y < 0)
            return false;
        else if(X == 0 && Y == 0)
            surPiste = false;
        else
            surPiste = true;
        this.X = X;
        this.Y = Y;
        return true;
    }

    public boolean ajouterOccupant(String occupant) {
        if(occupant != null && !occupée) {
            occupée = true;
            this.occupant = occupant;
            return true;
        }
        return false;
    }

    public boolean enlèverOccupant() {
        if(occupée) {
            occupée = false;
            occupant = "undefined";
            éteindre();
            return true;
        }
        return false;
    }

    public boolean allumer() {
        if(occupée) {
            allumée = true;
            return true;
        }
        return false;
    }

    public boolean éteindre() {
        if(allumée) {
            allumée = false;
            arrêterClignotement();
            return true;
        }
        return false;
    }

    public boolean démarrerClignotement() {
        if(allumée) {
            clignotante = true;
            return true;
        }
        return false;
    }

    public boolean arrêterClignotement() {
        if(clignotante) {
            clignotante = false;
            return true;
        }
        return true;
    }

    public boolean estOccupée() {
        return occupée;
    }

    public String getOccupant() {
        return occupant;
    }

    public boolean estAllumée() {
        return allumée;
    }

    public boolean estClignotante() {
        return clignotante;
    }

    @Override
    public String toString() {
        String s = "["+ id + "] (" + X + "," + Y + ") ";
        if(!occupée)
            s += "libre éteinte non clignotante";
        else if(!allumée)
            s += "occupée (" + occupant + "éteinte non clignotante";
        else if(!clignotante)
            s += "occupée (" + occupant + "allumée non clignotante";
        else
            s += "occupée (" + occupant + "allumée clignotante";
        return s;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj != null || this.getClass() == obj.getClass()) {
            Autotamponneuse auto = (Autotamponneuse) obj;
            return id == auto.id;
        }
        return false;
    }
}
