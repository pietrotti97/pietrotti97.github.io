import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

class Persona
{
    private String nome;
    private String cognome;
    public Persona(String n, String c)
    {
        this.nome=n;
        this.cognome=c;
    }
    public String toString()
    {
        return ("nome: "+nome+ "\t cognome: "+ cognome);
        
    }
}
public class ProvaC1
{
    public static void main(String[] args)
    {
        String[] nomi = new String[] { "aldo", "Luca", "maria"};
        String[] cognomi = new String[]{"Rossi","Bianchi"};
        Persona[] mazzoPersone = new Persona[6];
        int k=0;
        for(int i=0;nomi.lenght;i++)
        {
            for(int j=0;i<cognomi.lenght; j++)
            {
                mazzoPersone[k]=new Persona(nomi[i], cognomi[j]);
                k++;
            }
            try
            {
                PrintWriter output=new PrintWriter(new FileWriter("persone.txt"));
                output.println(mazzoPersone[0]);
                output.println(mazzoPersone[1]);
                output.println(mazzoPersone[2]);
                output.close();
            }catch(IOException e)
            {
                e.printStackTrace();
            }
        }
        
    }
}