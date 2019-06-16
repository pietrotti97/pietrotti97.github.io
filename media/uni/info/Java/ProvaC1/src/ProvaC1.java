import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

/*
Programma che simula l'estrazione di 3 persone in modo casuale da un insieme di persone. 
*/
class Persona
{
    private String nome;
    private String cognome;
    public Persona(String n, String c)
    {
        this.nome=n;
        this.cognome = c;
    }

    public String toString()
    {
    return("nome: " +nome + "cognome: "+ cognome);
    }
}

public class ProvaC1
{
    public static void main(String[] args)
    {
        String[] nomi = new String[]{"aldo", "luca", "maria"};
        String[] cognomi = new String[]{"rossi","bianchi", "gialli"};
        Persona[] totPersone = new Persona[9];
        int k=0;
        int i;
        int j;
        for(i= 0;i < nomi.length; i++)
        {
            for (j=0;j < cognomi.length ;j++)
            {
                totPersone[k]=new Persona(nomi[i], cognomi [j]);
                k++;
            }
        }
        try
        {
            PrintWriter output = new PrintWriter (new FileWriter ("persone.txt"));
            output.println(totPersone[0]);
            output.println(totPersone[1]);
            output.println(totPersone[2]);
            output.close();
        }catch (IOException e)
        {
            e.printStackTrace();
        }
    }
    
}
