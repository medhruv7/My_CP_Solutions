import java.util.*;
import java.io.*;
 
 
public class Main {
 
    static int mod = (int) 1e9 + 7;
    static PrintWriter writer = new PrintWriter(System.out);
    static Reader reader = new Reader();
 
    static class Reader {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
 
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(
                new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
 
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1) {
                if (c == '\n') {
                    if (cnt != 0) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                buf[cnt++] = (byte)c;
            }
            return new String(buf, 0, cnt);
        }
 
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ') {
                c = read();
            }
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (neg)
                return -ret;
            return ret;
        }
 
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
 
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
 
            do {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
 
            if (c == '.') {
                while ((c = read()) >= '0' && c <= '9') {
                    ret += (c - '0') / (div *= 10);
                }
            }
 
            if (neg)
                return -ret;
            return ret;
        }
 
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0,
                                 BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
 
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
 
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
 
    static class helper {
 
        public static int multiplyMod(int a, int b) {
            a %= mod;
            b %= mod;
            return (int) (((long)a * b)%mod);
        }
 
        public static int addMod (int a, int b){
            a %= mod;
            b %= mod;
            return (int)(((long)a + b)%mod);
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
    
    static class DataStructures {
 
        static class Pair<T,U> {
            T a;
            U b;
            Pair(T a, U b){
                this.a = a;
                this.b = b;
            }
        }
 
        static class Multiset<T> {
            HashMap<T, Integer> cnt = new HashMap<>();
            TreeSet<T> multiset = new TreeSet<>();
 
            public void add(T ele){
                multiset.add(ele);
                cnt.put(ele, cnt.getOrDefault(ele, 0) + 1);
            }
 
            public void remove(T ele){
                if(cnt.get(ele) > 1){
                    cnt.put(ele, cnt.get(ele) - 1);
                }else{
                    cnt.put(ele, 0);
                    multiset.remove(ele);
                }
            }
        }
    }
    
    
    // public static class CompareCus<T> implements Comparator<T> {
    //     public int compare(T a, T b) {
    //         // implement the comparator here
    //     }
    // }
    static int X = 1000001;
    static int N = 101;
    static int n,x;
    static int a[] = new int[N];
    static int dp[] = new int[X];
    public static void main(String[] args) throws IOException {
        // Write Code Here
    
        // dp[i] -> total ways to make i using all elements available bottom up approach if we find dp[1] we can use that in dp[2] result too
        n = reader.nextInt();
        x = reader.nextInt();
        
        for(int i = 0;i < n; ++i) a[i] = reader.nextInt();
 
        int dp[] = new int[x + 1];
        dp[0] = 1;
 
        for(int i = 1;i <= x; ++i){
            for(int j = 0;j < n; ++j){
                if(i - a[j] >= 0){
                    dp[i] += dp[i - a[j]];
                    // only 100 will be added at a time so upper bound for mod is 100 < 1e9 + 7
                    if(dp[i] > mod) dp[i] -= mod;
                }
            }
            // writer.println(dp[i]);
        }
 
        writer.print(dp[x]);
        writer.flush();
        writer.close();
    }
}