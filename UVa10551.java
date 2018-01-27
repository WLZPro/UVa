import java.math.BigInteger;
import java.util.Scanner;

public class UVa10551 {

	public static void main(String[] args) {
		UVa10551 main = new UVa10551();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (true) {
			int base = inputScanner.nextInt();
			if (base == 0) break;
			BigInteger p = inputScanner.nextBigInteger();
			int m = inputScanner.nextInt();
			BigInteger bip = new BigInteger(p.toString(), base);
			bip = bip.mod(new BigInteger(String.valueOf(m), base));
			System.out.println(bip.toString(base));
		}
		inputScanner.close();
	}
}
