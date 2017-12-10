import java.util.HashMap;
import java.util.Scanner;
//import edu.princeton.cs.algs4.Stopwatch;
public class UVa11340 {

	public static void main(String[] args) {
		UVa11340 main = new UVa11340();
		main.begin();
	}
	void begin() {
		//Stopwatch watch = new Stopwatch();
		Scanner inputScanner = new Scanner(System.in);
		int tests = inputScanner.nextInt();
		inputScanner.nextLine();
		for (int i = 0; i < tests; i++) {
			int paidLetters = inputScanner.nextInt();
			inputScanner.nextLine();
			HashMap<Character, Integer> paidLetterList = new HashMap<>();
			for (int j = 0; j < paidLetters; j++) {
				String[] h = inputScanner.nextLine().split(" ");
				char letter = h[0].charAt(0);
				int cost = Integer.parseInt(h[1]);
				paidLetterList.put(letter, cost);
			}
			int lines = inputScanner.nextInt();
			inputScanner.nextLine();
			double cost = 0;
			for (int j = 0; j < lines; j++) {
				char[] line = inputScanner.nextLine().toCharArray();
				for (char f : line) {
					if (paidLetterList.containsKey(f)) {
						cost += paidLetterList.get(f);
					}
				}
			}
			System.out.format("%.2f$\n", cost / 100);
		}
		inputScanner.close();
		//System.out.println(watch.elapsedTime());
	}
} 
