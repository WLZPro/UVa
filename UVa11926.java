import java.util.Scanner;
import java.util.BitSet;
public class UVa11926 {

	public static void main(String[] args) {
		UVa11926 main = new UVa11926();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (true) {
			int singleTasks = inputScanner.nextInt();
			int multiTasks = inputScanner.nextInt();
			if (singleTasks == 0 && multiTasks == 0) {
				break;
			}
			BitSet set = new BitSet(1000000);
			int max = 0;
			boolean conflict = false;
			for (int i = 0; i < singleTasks; i++) {
				int startTime = inputScanner.nextInt();
				int endTime = inputScanner.nextInt();
				if (endTime > max) {
					max = endTime;
				}
				for (int j = startTime; j < endTime; j++) {
					if (set.get(j)) {
						conflict = true;
						break;
					}
					set.set(j);
				}
			}
			for (int i = 0; i < multiTasks; i++) {
				int startTime = inputScanner.nextInt();
				int endTime = inputScanner.nextInt();
				int repeatVal = inputScanner.nextInt();
				int timeLength = endTime - startTime;
				int timeNow = startTime;
				while (timeNow <= 1000000) {
					for (int j = timeNow; j < timeNow + timeLength; j++) {
						if (set.get(j)) {
							conflict = true;
							break;
						}
						set.set(j);
					}
					timeNow += repeatVal;
				}
			}
			if (conflict) {
				System.out.println("CONFLICT");
			} else {
				System.out.println("NO CONFLICT");
			}
		}
		inputScanner.close();
	}
}
