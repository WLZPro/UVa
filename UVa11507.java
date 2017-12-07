import java.util.Scanner;
public class UVa11507 {

	public static void main(String[] args) {
		UVa11507 main = new UVa11507();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		
		while (inputScanner.hasNextLine()) {
			int length = inputScanner.nextInt();
			if (length == 0) {
				break;
			}
			inputScanner.nextLine();
			String[] operations = inputScanner.nextLine().split(" ");
			String[] cases = {"+x", "-x", "+y", "-y", "+z", "-z"};
			int caseNow = 0;
			for (int i = 0; i < length - 1; i++) {
				String operation = operations[i];
				if (operation.equals("+y")) {
					if (caseNow == 2) {
						caseNow = 1;
					} else if (caseNow == 0) {
						caseNow = 2;
					} else if (caseNow == 1) {
						caseNow = 3;
					} else if (caseNow == 3) {
						caseNow = 0;
					}
				} else if (operation.equals("-y")) {
					if (caseNow == 0) {
						caseNow = 3;
					} else if (caseNow == 1) {
						caseNow = 2;
					} else if (caseNow == 2) {
						caseNow = 0;
					} else if (caseNow == 3) {
						caseNow = 1;
					}
				} else if (operation.equals("+z")) {
					if (caseNow == 0) {
						caseNow = 4;
					} else if (caseNow == 1) {
						caseNow = 5;
					} else if (caseNow == 4) {
						caseNow = 1;
					} else if (caseNow == 5) {
						caseNow = 0;
					}
				} else if (operation.equals("-z")) {
					if (caseNow == 0) {
						caseNow = 5;
					} else if (caseNow == 1) {
						caseNow = 4;
					} else if (caseNow == 4) {
						caseNow = 0;
					} else if (caseNow == 5) {
						caseNow = 1;
					}
				}
			}
			System.out.println(cases[caseNow]);
		}
		
		
		inputScanner.close();
	}
}
