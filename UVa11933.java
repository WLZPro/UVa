
import java.util.Scanner;
class UVa11933 {
    public static void main(String[] args) {
		UVa11933 main = new UVa11933();
		main.begin();
    }
    void begin() {
		Scanner inputScanner = new Scanner(System.in);
		while (true) {
			int n = inputScanner.nextInt();
			if (n == 0) {
				break;
			}
			int out1 = 0, out2 = 0;
			boolean a = true;
			while (n > 0) {
				int t = (n & (-n));
				if (a) {
					out1 += t;
				} else {
					out2 += t;
				}
				n -= t;
				a = !a;
			}
			System.out.println(out1 + " " + out2);	
		}
		inputScanner.close();
    } 
}



