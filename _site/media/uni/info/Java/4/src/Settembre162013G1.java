import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;


abstract class Persona 
{
    
    public String nome;
    public int anno;
    
    public Persona(String nome, int anno) 
    {
        
        this.nome = nome;
        this.anno = anno;
        
    }
    
    public abstract String whoAmI();
    
}

class Studente extends Persona 
{
    
    public int matricola;
    
    public Studente(String nome, int anno, int matricola) 
    {
        
        super(nome, anno);
        this.matricola = matricola;
        
    }
    
    public String whoAmI() 
    {
        
        return "Sono " + this.nome + " nato nel " + this.anno + " matricola n. " + this.matricola; 
        
    }
}

public class Settembre162013G1 
{
    
    public static void main (String [] args) 
    {
        
       Studente st1 = new Studente("Anna", 1997, 13344);
       Studente st2 = new Studente("Mario", 1997, 12345);

        try 
        {
            PrintStream output = new PrintStream(new FileOutputStream("output.txt"));

            output.println(st1.whoAmI());
            output.println(st2.whoAmI());

        } catch (FileNotFoundException e) {
            System.out.println("Errore: " + e);
            System.exit(1);
        } 
        
    }
}
