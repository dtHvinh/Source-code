/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package baitap7;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class BaiTap7 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        
        Name a = new Name(name);
        a.process();
    }
    
}
