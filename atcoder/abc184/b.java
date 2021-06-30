import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = sc.nextInt();
        String s = sc.next();
        for(int i = 0;i < n; ++i){
            if(s.charAt(i) == 'o'){
                x++;
            }else{
                if(x - 1 >= 0){
                    x--;
                }
            }
        }
        System.out.print(x);
        sc.close();
    }
}