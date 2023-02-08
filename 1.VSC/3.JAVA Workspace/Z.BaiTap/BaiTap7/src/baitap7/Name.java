/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package baitap7;

/**
 *
 * @author student
 */
public class Name {
    String FullName;
    String temp ="";
    String temp2 = "";
    
    private static boolean isChar(char x){
        if(x >= 'a' && x <= 'z' || x >= 'A' && x<= 'Z') return true;
        return false;
    }
    
    public Name(String FullName) {
        this.FullName = FullName;
    }
    

    public void process(){
        for(int i = this.FullName.length()-1 ; i>= 0 ;i--){
            if(isChar(this.FullName.charAt(i))) this.temp += this.FullName.charAt(i);
            else break;
        }
        for(int i = this.temp.length()-1 ; i >= 0 ; i-- ){
            this.temp2 += this.temp.charAt(i);
        }
        System.out.println("Name: " + this.temp2);
    }
    
 
}
