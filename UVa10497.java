import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Scanner;
import java.math.BigInteger;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 *
 * @author WLZ
 */
public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        Scanner in = new Scanner(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        UVa10497 solver = new UVa10497();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa10497 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            BigInteger[] a = new BigInteger[801];
            a[1] = BigInteger.ZERO;
            for (int i = 2; i <= 800; i++) {
                a[i] = BigInteger.valueOf(i).multiply(a[i - 1]).add(BigInteger.valueOf(-1).pow(i));
            }
            int n;
            while ((n = in.nextInt()) != -1) {
                out.println(a[n]);
            }
        }

    }
}

