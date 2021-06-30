import java.util.*;
import java.io.*;
 
public class Main {
 
    static int mod = (int) 1e9 + 7;
    static PrintWriter writer = new PrintWriter(System.out);
    static FastReader reader = new FastReader();
 
    static class Pair<T>{
 
        public T a,b;
        Pair (T a, T b){
            this.a = a;
            this.b = b;
        }   
 
    }
 
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
 
        public static <T> void incrementMap(T key, HashMap<T, Integer> hashMap){
            hashMap.put(key, (int) hashMap.getOrDefault(key, 0) + 1);
        }
 
        
        public static <T> void decrementMap(T key, HashMap<T, Integer> hashMap){
            hashMap.put(key, (int) hashMap.getOrDefault(key, 0) - 1);
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
    
 
    
    public static void solve(int n, int from, int to, int aux, List<Pair> ans) {
        if(n > 0){
            // Move the n - 1 plates to aux
            solve(n - 1 , from, aux, to, ans);
 
            // Put the last Disk to Destination
            ans.add(new Pair(from, to));
 
            // Put Remaining Disks From Aux to Dest
 
            solve(n - 1, aux, to, from, ans);
        }
    }
 
    public static void main(String[] args) {
        // Write Code Here
 
        int n = reader.nextInt();
 
        List<Pair> ans = new ArrayList<>();
 
        solve(n, 1, 3, 2, ans);
 
        writer.println(ans.size());
 
        for(Pair el : ans){
            writer.println(el.a + " " +  el.b);
        }
 
        writer.flush();
        writer.close();
    }
}
