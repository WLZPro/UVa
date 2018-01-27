import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class UVa11821 {

	public static void main(String[] args) {
		UVa11821 main = new UVa11821();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		int TC = inputScanner.nextInt();
		while (TC-->0) {
			BigDecimal bd = BigDecimal.ZERO;
			while (true) {
				BigDecimal val = inputScanner.nextBigDecimal();
				if (val.equals(BigDecimal.ZERO)) break;
				bd = bd.add(val);
			}
			bd = bd.setScale(30, RoundingMode.HALF_UP).stripTrailingZeros();
			System.out.println(bd.toPlainString());
		}
		inputScanner.close();
	}
}
