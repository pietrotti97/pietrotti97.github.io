import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
/**
 *
 * @author pietro
 */
class Carta 
{
    private String valore;
    private String seme;
    public Carta(String v, String s)
    {
        this.valore=v;
        this.seme=s;
    }
    public boolean equals (Object x)
    {
        return this.seme.equals(((Carta)x).seme) && this.valore.equals(((Carta)x).valore);
    }
}
    /**
     * @param args the command line arguments
     */
public class CartaSeme 
{
    
    public static void main(String[] args) 
    {
        // TODO code application logic here
        Carta[] mazzo=new Carta[4];
        mazzo[0] = new Carta("Asso", "cuori");
        mazzo[1]=new Carta("Due","Quadri");
        mazzo[3]=new Carta("Cinque","quadri");
        try
        {
            PrintWriter output = new PrintWriter(new FileWriter ("out.txt"));
            if(mazzo[0].equals(mazzo[1]))
                output.println("uguali");
            else
                output.println("diversi");
            output.close();
        }catch (IOException e)
        {
            e.printStackTrace();
        }
        
                
    }
    
}
