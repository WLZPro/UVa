import java.math.BigInteger;
import java.util.Scanner;

public class UVa623 {

	public static void main(String[] args) {
		UVa623 main = new UVa623();
		main.begin();	
	}
	
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (inputScanner.hasNextInt()) {
			int n = inputScanner.nextInt();
			System.out.println(n + "!");
			System.out.println(fac(n));
		}
		inputScanner.close();
	}
	
	BigInteger fac(int h) {
		if (h == 0) return BigInteger.ONE;
		else return BigInteger.valueOf(h).multiply(fac(h - 1));
	}
}
