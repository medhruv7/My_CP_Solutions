package Introductory;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // Write Code Here
        
        String s = sc.next();
        int ans = 0;
        for(int i = 0;i < s.length(); ++i){
            int cur = 1;
            while(i + 1 < s.length() && s.charAt(i + 1) == s.charAt(i)){
                cur++;
                i++;
            }
            ans = Math.max(ans, cur);
        }

        System.out.print(ans);
        sc.close();
    }
}