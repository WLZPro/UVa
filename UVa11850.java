import java.util.Arrays;
import java.util.Scanner;

class UVa11850 {
	public static void main(String[] args) {
		UVa11850 main = new UVa11850();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (true) {
			int stops = inputScanner.nextInt();
			if (stops == 0) {
				break;
			}
			int[] locations = new int[stops];
			for (int i = 0;i < stops; i++) {
				locations[i] = inputScanner.nextInt();
			}
			Arrays.sort(locations);
			int locNow = 0;
			boolean impossible = false;
			for (int i = 0; i < stops; i++) {
				if (locations[i] - locNow > 200) {
					impossible = true;
					break;
				}
				locNow = locations[i];
			}
			if ((1422 - locNow) * 2 > 200) {
				impossible = true;
			}
			for (int i = stops - 2; i >= 0; i--) {
				if (locNow - locations[i] > 200) {
					impossible = true;
					break;
				}
				locNow = locations[i];
			}
			if (locNow > 200) {
				impossible = true;
			}
			if (impossible) {
				System.out.println("IMPOSSIBLE");
			} else {
				System.out.println("POSSIBLE");
			}
		}
		inputScanner.close();
	}
}
