import java.io.*;

interface Comparabile {
    public boolean maggioreDi(Object x);
}

class Bambino implements Comparabile {
    private int eta;
    private String nome;

    public Bambino (int n, String nome) {
        this.eta = n;
        this.nome = nome;
    }

    public boolean maggioreDi(Object x) {
        Bambino altro = (Bambino)x;
        if (eta>altro.eta) return true;
        else return false;
    }
    public String toString() {
        return(nome  + " " + eta + "\n");
    }
}

public class Prova {
    @SuppressWarnings("empty-statement")
    public static void main(String[] args) 
    {
        Bambino b1 = new Bambino(13,”elena”);
        Bambino b2 = new Bambino(14, “luca”);
        System.out.println("Il bambino maggiore:\n");
        if (b1.maggioreDi(b1)) 
            System.out.println(b1);
        else System.out.println(b2);
    }
}