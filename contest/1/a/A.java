import java.io.*;
import java.util.StringTokenizer;

/**
 * Problem: 1A
 * Author: ailurus2233
 * Time: 2022-03-19 01:04:56
 **/

public class A {
    public static void main(String[] args) throws Exception {
        FastScanner fr = new FastScanner();
        // Code Block
        long m = fr.nextLong(), n = fr.nextLong(), a = fr.nextLong();
        System.out.println((long) (Math.ceil(((double) m) / a) * Math.ceil(((double) n )/ a)));
        // please AC!
    }

    static class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        public FastScanner()
        {
            br = new BufferedReader(
                    new InputStreamReader(System.in));
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
