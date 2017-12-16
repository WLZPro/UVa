import java.util.BitSet;
import java.util.Scanner;

public class UVa599 {

	public static void main(String[] args) {
		UVa599 main = new UVa599();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		int cases = Integer.parseInt(inputScanner.nextLine());
		for (int i = 0; i < cases; i++) {
			BitSet connected = new BitSet(26);
			int E = 0, V, notAcrons = 0;
			while (true) {
				String input = inputScanner.nextLine();
				if (input.charAt(0) == '*') {
					break;
				}
				int first = ((int) input.charAt(1)) - 64;
				int last = ((int) input.charAt(3)) - 64;
				if (last != first) {
					if (!connected.get(first - 1)) notAcrons++;
					if (!connected.get(last - 1)) notAcrons++;
					connected.set(first - 1);
					connected.set(last - 1);
					E++;
				}
				//System.out.println(notAcrons);
			}
			String vertices = inputScanner.nextLine();
			V = vertices.length() != 0 ? vertices.length() / 2 + 1 : 0;
			System.out.println("There are " + (V - E - (V - notAcrons)) + " tree(s) and " + (V - notAcrons) + " acorn(s).");
		}
		inputScanner.close();
	}
}
