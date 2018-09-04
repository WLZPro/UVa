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
        UVa1431 solver = new UVa1431();
        solver.solve(1, in, out);
        out.close();
    }

    static class UVa1431 {
        public void solve(int testNumber, Scanner in, PrintWriter out) {
            BigInteger n, d;
            int e;
            int qq = 1;
            while (true) {
                n = in.nextBigInteger();
                d = in.nextBigInteger();
                e = in.nextInt();
                if (n.equals(BigInteger.ZERO) && d.equals(BigInteger.ZERO) && e == 0) {
                    break;
                }
                BigInteger product = n;
                BigInteger p = BigInteger.ZERO, q = BigInteger.ZERO;
                for (int k = 1; k < e; k++) {
                    if (d.multiply(BigInteger.valueOf(e)).subtract(BigInteger.ONE).mod(BigInteger.valueOf(k)).equals(BigInteger.ZERO)) {
                        //  (p + q) = -(de - 1) / k + 1 + n
                        //  (p + q) = -(de - 1) / k + 1 + n
                        BigInteger tmp = d.multiply(BigInteger.valueOf(e)).subtract(BigInteger.ONE).divide(BigInteger.valueOf(k));
                        BigInteger sum = tmp.negate().add(BigInteger.ONE).add(n);
                        // p, q = roots of (x^2 - sum * x + product)
                        sum = sum.negate();
                        BigInteger newP, newQ;
                        BigInteger discriminant = sum.multiply(sum).subtract(product.multiply(BigInteger.valueOf(4l)));
                        if (sqrt(discriminant).equals(BigInteger.ONE.negate())) {
                            continue;
                        }
                        BigInteger nom = sum.negate().add(sqrt(discriminant));
                        if (!nom.mod(BigInteger.valueOf(2l)).equals(BigInteger.ZERO)) {
                            continue;
                        }
                        newP = nom.divide(BigInteger.valueOf(2l));
                        nom = sum.negate().subtract(sqrt(discriminant));
                        if (!nom.mod(BigInteger.valueOf(2l)).equals(BigInteger.ZERO)) {
                            continue;
                        }
                        newQ = nom.divide(BigInteger.valueOf(2l));
                        p = newP;
                        q = newQ;
                    }
                }
                if (p.compareTo(q) > 0) {
                    BigInteger t = p;
                    p = q;
                    q = t;
                }
                out.println("Case #" + qq++ + ": " + p + " " + q);
            }
        }

        BigInteger sqrt(BigInteger x) {
            BigInteger lo = BigInteger.ONE;
            BigInteger hi = x;
            while (lo.add(BigInteger.ONE).compareTo(hi) < 0) {
                BigInteger mid = lo.add(hi).divide(BigInteger.valueOf(2l));
                int cmp = mid.multiply(mid).compareTo(x);
                if (cmp == 0) {
                    return mid;
                } else if (cmp < 0) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            return BigInteger.ONE.negate();
        }

    }
}

