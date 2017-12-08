import java.math.RoundingMode;
import java.text.DecimalFormat;
import java.util.Scanner;

public class UVa579 {

	public static void main(String[] args) {
		UVa579 main = new UVa579();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (inputScanner.hasNextLine()) {
			String[] input = inputScanner.nextLine().split(":");
			if (input[0].equals("0") && input[1].equals("00")) {
				break;
			}
			int hour = Integer.parseInt(input[0]);
			int minute = Integer.parseInt(input[1]);
			double minuteDegree = minute * 6;
			double hourDegree = hour * 30 + minute * 0.5;
			double result = Math.min(Math.abs(minuteDegree - hourDegree), Math.abs(360 - Math.abs(minuteDegree - hourDegree)));
			DecimalFormat bd = new DecimalFormat();
			bd.setMinimumFractionDigits(3);
			bd.setRoundingMode(RoundingMode.HALF_UP);
			result = Double.parseDouble(bd.format(result));
			boolean f = false;
			try {
				@SuppressWarnings("unused")
				String output = ("" + result).split(".")[1];
			} catch (ArrayIndexOutOfBoundsException e) {
				System.out.println(result + "00");
				f = true;
			}
			if (!f) {
				System.out.println(result + "0");
			}
		}
		inputScanner.close();
	}
}
