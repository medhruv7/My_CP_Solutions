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
    
    static class Event {
        long tm;
        boolean isArrive;
        int ind;
        Event(long tm, boolean isArrive, int ind){
            this.tm = tm;
            this.isArrive = isArrive;
            this.ind = ind;
        }
    }
    
    public static class CompareCus implements Comparator<Event> {
        public int compare(Event a, Event b) {
            if(a.tm != b.tm) return (int) (a.tm - b.tm);
            else{
                if(a.isArrive) return -1;
                else return 1; 
            }
        }
    }
 
    public static void main(String[] args) {
        // Write Code Here
 
        int n = reader.nextInt();
        ArrayList<Event> ar = new ArrayList<>();
        for(int i = 0;i < n; ++i){
            ar.add(new Event(reader.nextInt(), true, i));
            ar.add(new Event(reader.nextInt(), false, i));
        }
 
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = 0;i < n; ++i) ans.add(0);
        Collections.sort(ar, new CompareCus());
 
        int ansMax = 0;
        HashSet<Integer> avail = new HashSet<>();
 
        for(int i = 0;i < ar.size(); ++i){
            if(ar.get(i).isArrive){
                if(avail.size() == 0){
                    ans.set(ar.get(i).ind, ++ansMax);
                }else{
                    ans.set(ar.get(i).ind, avail.iterator().next());
                    avail.remove(avail.iterator().next());
                }
            }else{
                avail.add(ans.get(ar.get(i).ind));
            }
        }
 
        writer.println(ansMax);
        for(Integer a : ans){
            writer.print(a + " ");
        }
 
        writer.flush();
        writer.close();
    }
}