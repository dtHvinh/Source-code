/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package baitap6;
import java.lang.Math;
/**
 *
 * @author student
 */
public class check {
    public static boolean isPrime(int n){
        if(n < 2) return false;
        for(int i = 2 ;i < Math.sqrt(n) ; i++){
            if(n % i == 0) return false;
        }
        return true;
    }
}
