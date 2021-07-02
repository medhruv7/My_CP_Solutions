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