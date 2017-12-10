import java.util.Scanner;
import java.util.LinkedList;
public class UVa11988 {

	public static void main(String[] args) {
		UVa11988 main = new UVa11988();
		main.begin();
	}
	void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (inputScanner.hasNextLine()) {
			String input = inputScanner.nextLine();
			LinkedList<String> strList = new LinkedList<>();
			int startPos = 0;
			boolean addfirst = false;
			for (int i = 0; i < input.length(); i++) {
				char c = input.charAt(i);
				if (c == '[') {
					String str;
					if (i > startPos) {
						str = input.substring(startPos, i);
						if (addfirst) {
							strList.addFirst(str);
						} else {
							strList.addLast(str);
						}
						
					}
					addfirst = true;
					startPos = i + 1;
				} else if (c == ']') {
					String str;
					if (i > startPos) {
						str = input.substring(startPos, i);
						if (addfirst) {
							strList.addFirst(str);
						} else {
							strList.addLast(str);
						}
					}
					addfirst = false;
					startPos = i + 1;
				}
			}
			if (input.length() > startPos) {
				String substr = input.substring(startPos, input.length());
				if (addfirst) {
					strList.addFirst(substr);
				} else {
					strList.addLast(substr);
				}
			}
			StringBuilder sb = new StringBuilder();
			for (String s : strList) {
				sb.append(s);
			}
			System.out.println(sb.toString());
		}
		inputScanner.close();
	}
}
