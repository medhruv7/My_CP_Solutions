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
    
    public static void main(String[] args) {
        // Write Code Here

        int n = reader.nextInt();
        int x = reader.nextInt();
        HashMap<Integer,  HashSet<Integer>> cnt = new HashMap<>();
        ArrayList<Integer> ar = new ArrayList<>();

        for(int i = 0;i < n; ++i){
            int y = reader.nextInt();
            ar.add(y);
            if(cnt.containsKey(y)){
                cnt.get(y).add(i);
            }else{
                HashSet<Integer> hs = new HashSet<>();
                hs.add(i);
                cnt.put(y, hs);
            }
        }
        
        int ans1 = -1,ans2 = -1;
        for(int i = 0;i < n; ++i){
            if(cnt.containsKey(x - ar.get(i))){
                cnt.get(x - ar.get(i)).remove(i);
                if(cnt.get(x - ar.get(i)).size() > 0){
                    ans1 = i;
                    ans2 = cnt.get(x - ar.get(i)).iterator().next();
                    break;
                }
                cnt.get(x - ar.get(i)).add(i);
            }
        }

        if(ans1 == -1){
            writer.print("IMPOSSIBLE");
        }else{
            writer.print((ans1 + 1) + " " + (ans2 + 1));
        }
        writer.flush();
        writer.close();
    }
}