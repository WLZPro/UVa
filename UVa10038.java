import java.util.Arrays;
import java.util.Scanner;

public class UVa10038 {

	public static void main(String[] args) {
		UVa10038 main = new UVa10038();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (inputScanner.hasNextLine()) {
			int length = inputScanner.nextInt();
			int[] vals = new int[length];
			for (int i = 0; i < length; i++) {
				vals[i] = inputScanner.nextInt();
			}
			int[] diffs = new int[length - 1];
			for (int i = 1; i < length; i++) {
				diffs[i - 1] = Math.abs(vals[i] - vals[i - 1]);
			}
			Arrays.sort(diffs);
			boolean found = true;
			for (int i = 0; i < length - 1; i++) {
				if (diffs[i] != i + 1) {
					found = false;
					break;
				}
			}
			if (!found) {
				System.out.println("Not jolly");
			} else {
				System.out.println("Jolly");
			}
			inputScanner.nextLine();
		}
		inputScanner.close();
	}

}
