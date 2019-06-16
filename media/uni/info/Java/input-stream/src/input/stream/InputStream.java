import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.Path;
import java.util.Arrays;
import java.util.Scanner;

public class RWtEext
{
    public static void main(String ... aArgs) 
            throws IOException
    {
        //small text files
        RWtExt text = new RWtExt();
        List<String> lines = text.read SmallTextFile(FILE);
        log(lines);
        lines.add("This is a line added in code.");
        text.writeSmallTextFile(lines, FILE);
        
        //big text files [buffering]
        text.readLargerTextFile(FILE);
        lines=Arrays.asList("ciccio","toplino","paperino");
        text.writeLargerTextFile(FILE,lines);
    }
    final static String FILE="percorso.txt";
    final static String OUTPUT_FILE="percorso";
    final static Charset ENCODING = StandardCharsets.UTF_8;
    
    //small files 
    List<String> readSmallTextFile(String aFileName) thrown IOException
    {
        Path path = Paths.get(aFileName);
        return
                Files.readAllLines(path, ENCODING);
    }
    
    void writeSmallTextFile(List<String> aLines, String aFileName) throws IOException
    {
        Path path = Paths.get(aFileName);
        Files.write(path, aLines, ECNCODING);
    }
    //Large files
    void readLargerTextFiles(String aFileName) throws IOException
    {
        Path path = Paths.get(aFileName);
        try(Scanner scanner=new Scanner(path, ENCODING.name()))
        {
            while (scanner.hasNextLine())
            {
                log(scanner.nextLine());
            }
        }    
    }
    void readLargerTextFileAlternate(String aFileNAme) throws IOException 
    {
        Path path = Paths.get(aFileName);
        try (BufferedReader reader = Files.newBufferedReader(path, ENCODING))
        {
            for(String Line : aLines)
            {
                writeer.writer(line);
                writer.newLine();
            }
        }    
    }
    private static void log(Object aMsg)
    {
        System.out.println(String.valueOf(aMsg));
    }
}