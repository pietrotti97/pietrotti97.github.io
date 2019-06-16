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
public class Contatore 
{
    private static int val;
    public static void reset() {val = 0;}
    public static void inc() {val++;}
    public static int getValue(){return val;}
    
}
