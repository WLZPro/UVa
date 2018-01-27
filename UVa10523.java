import java.util.Scanner;
import java.math.BigInteger;

public class UVa10523 {

	public static void main(String[] args) {
		UVa10523 main = new UVa10523();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (inputScanner.hasNextInt()) {
			int n = inputScanner.nextInt();
			int a = inputScanner.nextInt();
			BigInteger bi = BigInteger.ZERO;
			for (int i = 1; i <= n; i++) {
				BigInteger tmp = BigInteger.valueOf(a);
				tmp = tmp.pow(i);
				tmp = tmp.multiply(BigInteger.valueOf(i));
				bi = bi.add(tmp);
			}
			System.out.println(bi.toString());
		}
		inputScanner.close();
	}
}	
