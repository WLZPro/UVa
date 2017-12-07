import java.util.Scanner;

public class UVa10141 {

	public static void main(String[] args) {
		UVa10141 main = new UVa10141();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		int RFP = 1;
		while (inputScanner.hasNextLine()) {
			int requirements = inputScanner.nextInt();
			int proposals = inputScanner.nextInt();
			inputScanner.nextLine();
			if (requirements == 0 && proposals == 0) {
				break;
				
			} else {
				if (RFP != 1) {
					System.out.println();
				}
			}
			for (int i = 0; i < requirements; i++) {
				inputScanner.nextLine();
			}
			int bestVal = 0;
			double bestPrice = Double.MAX_VALUE;
			String bestName = "";
			for (int i = 0; i < proposals; i++) {
				String name = inputScanner.nextLine();
				double price = inputScanner.nextDouble();
				int val = inputScanner.nextInt();
				inputScanner.nextLine();
				for (int j = 0; j < val; j++) {
					inputScanner.nextLine();
				}
				if (val > bestVal) {
					bestVal = val;
					bestPrice = price;
					bestName = name;
				} else if (val == bestVal) {
					if (price < bestPrice) {
						bestName = name;
						bestPrice = price;
					}
				}
			}
			System.out.println("RFP #" + RFP);
			System.out.println(bestName);
			RFP++;
		}
		inputScanner.close();
	}
}
