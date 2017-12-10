import java.util.PriorityQueue;
import java.util.Scanner;

public class UVa10954 {

	public static void main(String[] args) {
		UVa10954 main = new UVa10954();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		//while (inputScanner.hasNextLine()) {
		while (true) {
			int nums = inputScanner.nextInt();
			//inputScanner.nextLine();
			if (nums == 0) {
				break;
			}
			PriorityQueue<Integer> vals = new PriorityQueue<>();
			for (int i = 0; i < nums; i++) {
				int val = inputScanner.nextInt();
				vals.add(val);
			}
			int totalCost = 0;
			
			while (vals.size() >= 2) {
				int cost = vals.remove() + vals.remove();
				totalCost += cost;
				vals.add(cost);
			}
			System.out.println(totalCost);
		}
		inputScanner.close();
	}
}
