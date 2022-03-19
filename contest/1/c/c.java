import java.io.*;
import java.util.StringTokenizer;

/**
 * Problem:
 * Author: ailurus2233
 * Time: 2022-03-19 09:13:35
 **/

public class c {
    public static void main(String[] args) throws IOException {
        FastScanner fr = new FastScanner(System.in);
        // Code Block
        double ax = fr.nextDouble();
        double ay = fr.nextDouble();
        double bx = fr.nextDouble();
        double by = fr.nextDouble();
        double cx = fr.nextDouble();
        double cy = fr.nextDouble();

        double a = getDistant(bx, cx, by, cy);
        double b = getDistant(ax, cx, ay, cy);
        double c = getDistant(ax, bx, ay, by);

        double p = 0.5 * (a + b + c);

        double S = Math.sqrt(p * (p - a) * (p - b) * (p - c));
        double R = a * b * c / (4 * S);

        double phiA = getArccos(a, R);
        double phiB = getArccos(b, R);
        double phiC = getArccos(c, R);

        int num = 0;

        for (int i = 3; i <= 100; i++) {
            double theta = 2 * Math.PI / i;
            double tA = phiA/theta;
            long rA = Math.round(tA);
            double tB = phiB/theta;
            long rB = Math.round(tB);
            double tC = phiC/theta;
            long rC = Math.round(tC);
            if (Math.abs(tA - rA) < 1e-5 && Math.abs(tB - rB) < 1e-5 && Math.abs(tC - rC) < 1e-5) {
                num = i;
                break;
            }
        }
        System.out.printf("%.8f",  0.5 * R * R * Math.sin(2 * Math.PI/num) * num);
        // please AC!
    }

    static double getDistant(double x1, double x2, double y1, double y2) {
        return Math.sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    }

    static double getArccos(double d, double R) {
        double c = 1 - (d * d) / (2 * R * R);
        if (c > 1)
            c = 1;
        if (c < -1)
            c = -1;
        return Math.acos(c);
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
