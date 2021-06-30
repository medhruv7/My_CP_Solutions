import java.util.*;
import java.io.*;


public class Main {

    static int mod = (int) 1e9 + 7;
    static PrintWriter writer = new PrintWriter(System.out);
    static FastReader reader = new FastReader();

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;
        Character c;
        int curCharIndex = 0;
        String currentString = null;

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

       char nextChar(){
           Character ch = null;

           if(currentString == null){
               currentString = reader.nextString();
               curCharIndex = 0;
           }
           try{
               ch = currentString.charAt(curCharIndex++);
               if(curCharIndex == currentString.length()){
                   curCharIndex = 0;
                   currentString = null;
               }
           } catch(Exception e){
               e.printStackTrace();
           }

           return ch;
        }

    }

    static class helper {

        public static int multiplyMod(int a, int b) {
            return (int) (((long)a * b)%mod);
        }

        public static <T> void incrementMap(T key, HashMap<T, Integer> hashMap){
            hashMap.put(key, (int) hashMap.getOrDefault(key, 0) + 1);
        }

        
        public static <T> void decrementMap(T key, HashMap<T, Integer> hashMap){
            hashMap.put(key, (int) hashMap.getOrDefault(key, 0) - 1);
        }

        public static String sortString(String s){
            char[] c = s.toCharArray();
            Arrays.sort(c);
            return new String(c);
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
    
    static char[][] a = new char[8][8];
    static boolean[][] vis = new boolean[8][8];
    static boolean[] rowVis = new boolean[8];
    static boolean[] colVis = new boolean[8];
    static boolean[] diag1Vis = new boolean[20];
    static boolean[] diag2Vis = new boolean[20];

    static int ans = 0;
    
    public static boolean check(int i, int j){
        if(!vis[i][j] && !rowVis[i] && !colVis[j] && !diag1Vis[(i + j)] && !diag2Vis[(i - j + 8)%8] && a[i][j] != '*') return true;
        return false;
    }


    public static void solve(int cnt){
        if(cnt == 8){
            ans++;
            return;
        }
        
        for(int i = 0;i < 8; ++i){
            for(int j = 0;j < 8; ++j){
                if(check(i, j)){
                    vis[i][j] = true;
                    rowVis[i] = true;
                    colVis[j] = true;
                    diag1Vis[i + j] = true;
                    diag2Vis[(i - j + 8)%8] = true;
                    solve(cnt + 1);
                    vis[i][j] = false;
                    rowVis[i] = false;
                    colVis[j] = false;
                    diag1Vis[i + j] = false;
                    diag2Vis[Math.abs(i - j)] = false;
                }
            }
        }
    }
    
    public static void main(String[] args) {
        FastReader reader = new FastReader();
        // Write Code Here

        for(int i = 0;i < 8; ++i){
            for(int j = 0;j < 8; ++j){
                a[i][j] = reader.nextChar();
            }
        }

        solve(0);
        writer.print(ans);

        writer.flush();
        writer.close();
    }
}