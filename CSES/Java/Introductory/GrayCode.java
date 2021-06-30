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
    

    public static void solve(int n, List<Integer> res, HashSet<Integer> isDone){
        int current = res.get(res.size() - 1);
        for(int i = 0;i < n; i++){
            int next = current ^ (1<<i);
            if(!isDone.contains(next)){
                isDone.add(next);
                res.add(next);
                solve(n, res, isDone);
                if(res.size() == (1<<n)) return;
                isDone.remove(next);
                res.remove(res.size() - 1);
            }
        }
    }



    public static void main(String[] args) {
        PrintWriter writer = new PrintWriter(System.out);
        FastReader reader = new FastReader();
        // Write Code Here

        int n = reader.nextInt();
        List<Integer> res = new ArrayList<>();
        HashSet<Integer> isDone = new HashSet<>();
        res.add(0);
        isDone.add(0);

        solve(n, res, isDone);
        
        for(Integer ele : res){
            StringBuilder s = new StringBuilder();
            for(int i = 0;i < n; ++i){
                if(((ele>>i)&1) != 0){
                    s.append("1");
                }else{
                    s.append("0");
                }
            }

            writer.println(s.toString());
        }
        
        writer.flush();
        writer.close();
    }
}