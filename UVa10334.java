import java.math.BigInteger;
import java.util.Scanner;

public class UVa10334 {
	BigInteger[] fibArr = new BigInteger[1003];
	public static void main(String[] args) {
		UVa10334 main = new UVa10334();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		for (int i = 0; i < 1003; i++) {
			fibArr[i] = BigInteger.valueOf(-1);
		}
		while (inputScanner.hasNextBigInteger()) {
			int a = inputScanner.nextInt();
			System.out.println(fib(a + 2));
		}
		inputScanner.close();
	}
	BigInteger fib(int n) {
		if (!fibArr[n].equals(BigInteger.valueOf(-1))) return fibArr[n];
		if (n == 0) {
			fibArr[n] = BigInteger.ZERO;
			return BigInteger.ZERO;
		}
		if (n == 1) {
			fibArr[n] = BigInteger.ONE;
			return BigInteger.ONE;
		}
		else {
			BigInteger num = fib(n - 1).add(fib(n - 2));
			fibArr[n] = num;
			return num;
		}
	}
}
