package Introductory;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        // Write Code Here

        int n = sc.nextInt();
        long sm = (long) n*(n + 1)/2;
        for(int i = 0;i < n - 1; ++i){
            sm -= (long) sc.nextInt();
        }

        System.out.print(sm);
        sc.close();
    }
}