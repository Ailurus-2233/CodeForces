import java.io.*;
import java.util.StringTokenizer;

/**
 * Problem: 1B
 * Author: ailurus2233
 * Time: 2022-03-19 08:26:21
 **/

public class b {
    static int cI = 0;

    public static void main(String[] args) throws IOException {
        FastScanner fr = new FastScanner(System.in);
        // Code Block
        int n = fr.nextInt();
        for (int i = 0; i < n; i++) {
            String data = fr.nextLine();
            if (anaMethod(data))
                method1(data);
            else
                method2(data);
        }
        // please AC!
    }

    static boolean anaMethod(String data) {
        if (data.charAt(0) != 'R') return true;
        if (data.charAt(1) < 65 || data.charAt(1) > 90)
            for (int i = 2; i < data.length(); i++)
                if (data.charAt(i) == 'C') {
                    cI = i;
                    return false;
                }
        return true;
    }

    static void method1(String data) {
        int colI = 0;
        int col = 0, row = 0;
        for (int i = 0; i < data.length(); i ++)
            if (data.charAt(i) < 65) {
                colI = i-1;
                row = Integer.parseInt(data.substring(i, data.length()));
                break;
            }
        int p = 0;
        for (int i = colI; i >= 0; i--)
            col += (data.charAt(i) - 'A' + 1) * (int)Math.pow(26, p++);
        System.out.println("R" + row + "C" + col);
    }

    static void method2(String data) {
        int row = Integer.parseInt(data.substring(1, cI));
        int col = Integer.parseInt(data.substring(cI + 1, data.length()));
        String colS = "";
        while(col != 0) {
            int ans = col % 26;
            if (ans == 0) {
                colS = "Z" + colS;
                col -= 26;
            } else {
                col -= ans;
                colS = (char)(ans + 'A' - 1) + colS;
            }
            col /= 26;
        }
        System.out.println(colS + String.valueOf(row));
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
