import java.util.Scanner;
import java.math.BigInteger;

class Main {
    String x, z;
    boolean[][] vis;
    BigInteger[][] memo;
    public static void main(String[] args) {
        Main main = new Main();
        main.begin();
    }
    BigInteger solve(int i, int j) {
        if (j == z.length()) return BigInteger.ONE;
        if (i == x.length()) return BigInteger.ZERO;
        if (vis[i][j]) return memo[i][j];
        BigInteger ans = BigInteger.ZERO;
        ans = ans.add(solve(i + 1, j));
        if (x.charAt(i) == z.charAt(j)) {
            ans = ans.add(solve(i + 1, j + 1));
        }
        vis[i][j] = true;
        memo[i][j] = ans;
        return ans;
    }
    void begin() {
        Scanner sc = new Scanner(System.in);
        int TC = sc.nextInt();
        sc.nextLine();
        while (TC-->0) {
            memo = new BigInteger[10005][105];
            vis = new boolean[10005][105];
            x = sc.nextLine();
            z = sc.nextLine();
            System.out.println(solve(0, 0));
        }
        sc.close();
    }
}