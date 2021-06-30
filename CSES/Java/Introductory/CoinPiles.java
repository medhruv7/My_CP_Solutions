package Introductory;
import java.util.*;
import java.io.*;


public class Main {

    static int mod = (int) 1e9 + 7;

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String nextString() {
            while(st == null || !st.hasMoreElements()){
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            
            return st.nextToken();
        }

       int nextInt() {
           return Integer.parseInt(nextString());
       }

       long nextLong() {
           return Long.parseLong(nextString());
       }

       double nextDouble() {
           return Double.parseDouble(nextString());
       }
    }

    static class helper {

        public static int multiplyMod(int a, int b) {
            return (int) (((long)a * b)%mod);
        }

    }

    static class algorithms {

        public static int binpow(int b, int p) {
            int res = 1;
            while(p > 0){
                if((p&1) != 0){
                    res = helper.multiplyMod(res, b);
                }
                b = helper.multiplyMod(b, b);
                p >>= 1;
            }
            return res;
        }

    }
    

    public static void main(String[] args) {
        PrintWriter writer = new PrintWriter(System.out);
        FastReader reader = new FastReader();
        // Write Code Here
        
        int n = reader.nextInt();
        for(int i = 0;i < n; ++i){
            int a = reader.nextInt();
            int b = reader.nextInt();
            if(Math.max(a, b) > 2*Math.min(a, b)){
                writer.println("NO");
            }
            else if((a + b)%3 == 0){
                writer.println("YES");
            }else{
                writer.println("NO");
            }
        }
        writer.flush();
        writer.close();
    }
}
