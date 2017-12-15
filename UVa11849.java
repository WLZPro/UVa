import java.util.TreeSet;
import java.util.Scanner;

public class UVa11849 {

	public static void main(String[] args) {
		UVa11849 main = new UVa11849();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (true) {
			int jillCds = inputScanner.nextInt();
			int jackCds = inputScanner.nextInt();
			if (jillCds == 0 && jackCds == 0) {
				break;
			}
			TreeSet<Long> jillCd = new TreeSet<>();
			int both = 0;
			for (int i = 0; i < jillCds; i++) {
				long val = inputScanner.nextInt();
				jillCd.add(val);
			}
			for (int i = 0; i < jackCds; i++) {
				long val = inputScanner.nextInt();
				if (jillCd.contains(val)) {
					both++;
				}
			}
			System.out.println(both);
		}
		inputScanner.close();
	}
}
