/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package pkg2;
/**
 *
 * @author pietro
 */
public class Main 
{
    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        int n;
        Contatore.reset();
        Contatore.inc();
        n = Contatore.getValue();
        System.out.println(n);
    }   
}
