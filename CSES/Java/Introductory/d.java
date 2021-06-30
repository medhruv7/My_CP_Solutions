package Introductory;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Write Code Here
        
        int n = sc.nextInt();
        int a = sc.nextInt();
        long ans = 0;
        for(int i = 0;i < n - 1; ++i){
            int b = sc.nextInt();
            if(b < a) {
                ans += a - b;
            }else{
                a = b;
            }
        }

        System.out.print(ans);
        sc.close();
    }
}
