import java.util.Scanner;

public class UVa272 {

	public static void main(String[] args) {
		UVa272 main = new UVa272();
		main.begin();
	}
	
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		String input;
		boolean first = true;
		while (inputScanner.hasNextLine()) {
			input = inputScanner.nextLine();
			for (int i = 0; i < input.length(); i++) {
				if (input.charAt(i) == '\u001a') {
					break;
				}
				if (input.charAt(i) == '\"') {
					if (first) {
						System.out.print("``");
						first = false;
						continue;
					} else {
						System.out.print("''");
						first = true;
						continue;
					}
				}
				System.out.print(input.charAt(i));
				
			}
			System.out.print("\n");
		}
		inputScanner.close();
	
	}
}

