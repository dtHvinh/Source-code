/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package baitap8;

import java.util.Scanner;

/**
 *
 * @author student
 */
public class BaiTap8 {
    public static void main(String[] args) {
        List a = new List();
        Scanner sc = new Scanner(System.in);
        // Nhap n
        System.out.println("Nhap n: ");
        int n = sc.nextInt();
        // Nhap danh sach
        while(n-->=1){
            int c = sc.nextInt();
            a.push(c);
        }
        // Tim tan suat cua f;
        int f = sc.nextInt();
        a.countNumber(f);
        // Sap xep tang dan
        a.sort();
    }   
}
