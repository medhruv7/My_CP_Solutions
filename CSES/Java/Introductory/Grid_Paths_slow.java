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
            
            currentString = st.nextToken();
            return currentString;
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

    static int ans = 0;
    static String s = null;
    static boolean vis[][] = new boolean[7][7];

    static boolean valid(int x, int y){
        if(x >= 0 && y >= 0 && x < 7 && y < 7) return true;
        return false;
    }

    static void solve(int ind, int x, int y){
        if(!valid(x, y) || vis[x][y]){
            return;
        }
        if(ind == s.length()){
            if(x == 0 && y == 6){
                ans++;
            }
            return;
        }
        vis[x][y] = true;
        if(s.charAt(ind) != '?'){
            if(s.charAt(ind) == 'U') solve(ind + 1, x, y - 1);
            if(s.charAt(ind) == 'D') solve(ind + 1, x, y + 1);
            if(s.charAt(ind) == 'L') solve(ind + 1, x - 1, y);
            if(s.charAt(ind) == 'R') solve(ind + 1, x + 1, y);
        }else{
            solve(ind + 1, x - 1, y);
            solve(ind + 1, x + 1, y);
            solve(ind + 1, x, y + 1);
            solve(ind + 1, x, y - 1);
        }
        vis[x][y] = false;
    }

    public static void main(String[] args) {
        // Write Code Here

        s = reader.nextString();
        solve(0, 0, 0);
        writer.print(ans);

        writer.flush();
        writer.close();
    }
}