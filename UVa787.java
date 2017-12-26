import java.math.BigInteger;
import java.util.Scanner;

class UVa787 {

	public static void main(String[] args) {
		Scanner inputScanner = new Scanner(System.in);
		while (inputScanner.hasNextInt()) {
			int[] vals = new int[101];
			int[] zeroPositions = new int[101];
			int n = 0 ,n2 = 0;
			while (true) {
				int val = inputScanner.nextInt();
				if (val == -999999) {
					break;
				}
				if (val == 0) {
					zeroPositions[n2++] = n;
				}
				vals[n] = val;
				n++;
			}
			
			zeroPositions[n2++] = n;
			
			BigInteger result = maxProduct(0,zeroPositions[0]-1, vals);
			
			for (int i = 1; i < n2; i++) {
				BigInteger a = maxProduct(zeroPositions[i - 1] + 1, zeroPositions[i] - 1, vals);
				
				if (a.compareTo(result) > 0) {
					result = a;
				}
			}
			
			if (n2 > 1 && result.compareTo(new BigInteger("0")) < 0) {
				result = new BigInteger("0");
			}

			System.out.println(result.toString());
		}
		inputScanner.close();
	}
	
	static BigInteger maxProduct(int start, int end, int[] arr) {
		if (end < start) {
			return new BigInteger("0");
		}
		
		if (end == start) {
			return new BigInteger(String.valueOf(arr[start]));
		}
		
		BigInteger out = null;
		int negatives = 0 ,firstNeg = -1, lastNeg = -1;
		for (int i = start; i < end + 1; i++) {
			if (arr[i] < 0) {
				negatives++;
				if (firstNeg < 0) {
					firstNeg = i;
				}
				lastNeg = i;
			}
			
		}
		if (negatives % 2 == 0) {
			out = new BigInteger("1");
			for (int i = start; i < end + 1; i++) {
				out = out.multiply(new BigInteger(String.valueOf(arr[i])));
			}
			
		} else {
			out = new BigInteger("1");
			boolean k = false;
			for (int i = firstNeg + 1; i < end + 1; i++) {
				k = true;
				out = out.multiply(new BigInteger(String.valueOf(arr[i])));
			}
			
			if (!k) {
				out = new BigInteger(String.valueOf(arr[firstNeg]));
			}
			BigInteger out2 = new BigInteger("1");
			for (int i = start; i < lastNeg; i++) {
				k = true;
				out2 = out2.multiply(new BigInteger(String.valueOf(arr[i])));
			}
			if (k) {
				if (out2.compareTo(out) > 0) {
					out = out2;
				}
			} 
			
		}
		return out;
	}
}
