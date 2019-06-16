import java.io.FileOutputStream;
import java.io.PrintStream;

abstract class Persona
{
    public String nome;
    public int anno;
    public Persona(String nome, int anno)
    {
        this.nome=nome;
        this.anno=anno;
    }
    public abstract String whoAmI();
}
class Studente extends Persona
{
    public int matricola;
    public Studente(String nome, int anno, int matricola)
    {
        super(nome,anno);
        this.matricola=matricola;
    }
    public String whoAmI()
    {
        return ("sono"+this.nome+"nato nel"+this.anno+"matricola: "+this.matricola);
    }
}
public class Main
{
    public static void main(String[] args)
    {
        Studente st1=new Studente ("Anna", 1997, 13344);
        Studente st2=new Studente("ciccio", 1998, 13345);
        try
        {
            PrintStream output=new PrintStream(new FileOutputStream("output.txt"));
            output.println(st1.whoAmI());
            output.println(st2.whoAmI());
        }catch(Exception e)
            {
                System.out.println("Errore: " + e);
                System.exit(1);
            }
        
    }
}