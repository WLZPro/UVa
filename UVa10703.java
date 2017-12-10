import java.util.Scanner;

public class UVa10703 {

	public static void main(String[] args) {
		UVa10703 main = new UVa10703();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (inputScanner.hasNextLine()) {
			int width = inputScanner.nextInt();
			int heigth = inputScanner.nextInt();
			int N = inputScanner.nextInt();
			inputScanner.nextLine();
			if (width == 0 && heigth == 0 && N == 0) {
				break;
			}
			boolean[][] spots = new boolean[500][500];
			int openSpots = width * heigth;
			for (int i = 0; i < N; i++) {
				int X1 = inputScanner.nextInt();
				int Y1 = inputScanner.nextInt();
				int X2 = inputScanner.nextInt();
				int Y2 = inputScanner.nextInt();
				for (int j = Math.min(X2,X1); j <= Math.max(X2, X1); j++) {
					for (int k = Math.min(Y1, Y2); k <= Math.max(Y1, Y2); k++) {
						if (!spots[j - 1][k - 1]) {
							spots[j - 1][k - 1] = true;
							openSpots--;
						}
					}
				}
			}
			if (openSpots == 0) {
				System.out.println("There is no empty spots.");
			} else if (openSpots == 1) {
				System.out.println("There is one empty spot.");
			} else {
				System.out.println("There are " + openSpots + " empty spots.");
			}
		}
		inputScanner.close();
	}
}
