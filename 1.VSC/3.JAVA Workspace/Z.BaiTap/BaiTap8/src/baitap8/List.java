/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package baitap8;

/**
 *
 * @author student
 */
public class List {
    int[] nums = new int[100];
    public static int n = 0;
    
    public void push(int x){
        this.nums[this.n++] = x;
    }
    
    public void countNumber(int x){
        int c = 0;
        for(int i = 0 ; i < this.n ; i++){
            if(this.nums[i] == x) c++;
        }
        System.out.println("So "+x+" xuat hien: "+c +" lan");
    }
    
    public void printList(){
        for(int i = 0 ; i < this.n ; i++){
            System.out.print(this.nums[i] + " ");
        }
    }
    
    public void sort(){
        for(int i = 0 ; i < this.n -1 ; i++){
            for(int j = i+1 ; j < this.n ; j++){
               if(this.nums[i] > this.nums[j]){
                   int tempe = this.nums[i];
                   this.nums[i] = this.nums[j];
                   this.nums[j] = tempe;
                }
            }
        }
        System.out.println("Mang da sap xep theo thu tu tang dan: ");
        printList();
    }
}
