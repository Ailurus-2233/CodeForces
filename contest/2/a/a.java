import java.io.*;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

/**
 * Problem:
 * Author: ailurus2233
 * Time: 2022-03-19 09:47:45
 **/

public class a {
    public static void main(String[] args) throws IOException {
        FastScanner fr = new FastScanner(System.in);
        // Code Block
        HashMap<String, Integer> pScore = new HashMap<>();
        HashMap<Integer, String> firstMan = new HashMap<>();
        String winner = "";
        int n = fr.nextInt();
        for (int i = 0; i < n; i++) {
            String name = fr.next();
            int score = fr.nextInt();
            if (pScore.containsKey(name)) 
                pScore.replace(name, pScore.get(name) + score);
            else 
                pScore.put(name, score);
            winner = getMax(pScore, firstMan);
        }

        // please AC!
    }

    static String getMax(HashMap<String, Integer> ps, HashMap<Integer, String> fm) {
        int max = -9999999;
        String name = "";
        for (String key: ps.keySet()) {
            if (ps.get(key) > max) {
                max = ps.get(key);
                name = key;
            }
        }
        if (!fm.containsKey(max)) {
            fm.put(max, name);
        }
        return name;
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public FastScanner(FileReader r) {
            br = new BufferedReader(r);
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreElements()) {
                st = new StringTokenizer(br.readLine());
            }
            return st.nextToken();
        }

        int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        double nextDouble() throws IOException {
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++)
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec)
                        f *= 10;
                }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        String nextLine() throws IOException {
            return br.readLine();
        }
    }
}
