import java.io.*;
interface Comparabile
        {
            public boolean maggioreDi(Object X);
        }
class Bambino implements Comparabile
{
    private String nome;
    private int eta;
    public Bambino ( int n, String nome)
    {
        this.nome = nome;
        this.eta = eta;
    }
    public boolean maggioreDi ( Object X)
    {
        Bambino altro = (Bambino)X;
        if(eta > altro.eta)
            return true;
        else
            return false;
    }
    public String toString()
    {
        return(nome + " "+eta+" \n");
    }
}
public class Main {
    public static void main(String[] args) 
    {
        Bambino b1 = new Bambino(13, "elena");
        Bambino b2 = new Bambino (12, "luca");
        System.out.println("il bambino maggiore e':  ");
        if(b1.maggioreDi(b2))
            System.out.println(b1);
        else
            System.out.println(b2);
    }    
}
