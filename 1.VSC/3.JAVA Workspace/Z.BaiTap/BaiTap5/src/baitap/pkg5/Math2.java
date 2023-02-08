/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package baitap.pkg5;
import java.lang.Math;
/**
 *
 * @author student
 */
public class Math2 {
    private int a,b,c;
    
    public static void solve(float a,float b,float c){
        float x1,x2;
        float delta = b*b - 4*a*c;
        if(delta < 0)
        {
            System.out.println("Vo Nghiem");
            return;
        }
        x1 = (float) (-1*b + Math.sqrt(delta))/2*a;
        x2 = (float) (-1*b - Math.sqrt(delta))/2*a;
        System.out.println("x1 = " + x1);
        System.out.println("x2 = " + x2);
    }
    public static void solve(float a,float b){
        if(a == 0)
        {
            System.out.println("Vo Nghiem");
            return;
        }
        System.out.println("x =" + (float) (-b/a));
    }
}
