/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package baitap3;

/**
 *
 * @author student
 */
public class List {
    float[] arr = new float[100];
    private static int n = 0;

    // Constructor
    public List() {
    }
    // Add element to a List
    public void insertList(float x){
        this.arr[this.n] = x;
        this.n++;
    }
    // 
    public void printList(){
        for(int i = 0 ; i < n ; i++){
            System.out.print(this.arr[i]+" ");
        }
        System.out.println();
    }
    
    public float max(){
        float max = 0;
        for(int i = 0 ; i < n ;i++){
            if(max < this.arr[i]) max = this.arr[i];
        }
        return max;
    }
    
    public float sum(){
        float sum = 0;
        for(float i : this.arr) sum += i;
        return sum;
    }

}
