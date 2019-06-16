import java.io.IOException;
import java.io.FileWriter;
import java.io.PrintWriter;
class Carta
{
    private String valore;
    private String seme;
    public Carta(String v, String s)
    {
        this.valore = v;
        this.seme = s;
    }
    public boolean equals (Object x)
    {
        return this.seme.equals(((Carta)x).seme) && this.valore.equals(((Carta)x).valore);
        
    }
}
public class ProvaC3
{
    public static void main(String[] args)
    {
        Carta[] mazzo = new Carta[3];
        mazzo[0]=new Carta("asso","cuori");
        mazzo[1]=new Carta("due","quadri");
        mazzo[2]=new Carta("cinque","quadri");
        try
        {
            PrintWriter output = new PrintWriter(new FileWriter("out.txt"));
            if(mazzo[0].equals(mazzo[1]))
                output.println("Uguali");
            else
                output.println("Diverse");
            output.close();
        }catch (IOException e)
        {
            e.printStackTrace();
        }
    }
}