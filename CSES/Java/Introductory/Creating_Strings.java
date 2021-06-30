import java.util.*;
import java.io.*;


public class Main {

    static int mod = (int) 1e9 + 7;
    static PrintWriter writer = new PrintWriter(System.out);
    static FastReader reader = new FastReader();

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
    

    static int cnt[] = new int[26];

    public static void solve(int n,ArrayList<Character> avail, StringBuilder s, ArrayList<String> ans){
        int len = s.length();
        if(len == n){
            ans.add(s.toString());
            return;
        }
        for(int i = 0;i < avail.size(); ++i){
            // Try this element at the current position
            if(cnt[avail.get(i) - 'a'] > 0) {
                cnt[avail.get(i) - 'a']--;
                s.append(avail.get(i));
                solve(n, avail, s, ans);
                s.deleteCharAt(s.length() - 1);
                cnt[avail.get(i) - 'a']++;
            }
        }
    }

    public static void main(String[] args) {
        FastReader reader = new FastReader();
        // Write Code Here

        String s = reader.nextString();
        s = helper.sortString(s);
        ArrayList<Character> avail = new ArrayList<>();
        ArrayList<String> ans = new ArrayList<>();

        for(int i = 0;i < s.length(); ++i){
            char x = s.charAt(i);
            avail.add(x);
            cnt[x - 'a']++;
            while((i + 1 < s.length()) && (s.charAt(i + 1) == x)) {
                i++;
                cnt[x - 'a']++;
            }
        }

        StringBuilder tmp = new StringBuilder();

        solve(s.length(), avail, tmp, ans);

        writer.println(ans.size());

        for(String el : ans){
            writer.println(el);
        }

        writer.flush();
        writer.close();
    }
}