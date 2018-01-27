import java.math.BigInteger;
import java.util.Scanner;

public class UVa11287 {

	public static void main(String[] args) {
		UVa11287 main = new UVa11287();
		main.begin();
	}
	
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (true) {
			int p = inputScanner.nextInt();
			int a = inputScanner.nextInt();
			if (p == 0 && a == 0) break;
			BigInteger bip = BigInteger.valueOf(p);
			BigInteger bia = BigInteger.valueOf(a);
			if (bia.modPow(bip, bip).equals(bia) && !bip.isProbablePrime(10)) {
				System.out.println("yes");
			} else {
				System.out.println("no");
			}
		}
		inputScanner.close();
	}
}
