import java.math.BigInteger;
import java.util.Scanner;

class UVa787NotOptimal {
	public static void main(String[] args) {
		Scanner inputScanner = new Scanner(System.in);
		while (inputScanner.hasNextInt()) {
			int[] vals = new int[200];
			int[] zeroPositions = new int[200];
			int n = 0, zeros = 0, negatives = 0, firstNeg = 0, lastNeg = 0;
			boolean first = true;
			while (true) {
				int val = inputScanner.nextInt();
				if (val == -999999) {
					break;
				}
				vals[n] = val;
				if (val == 0) {
					zeroPositions[zeros++] = n;
				} else if (val < 0) {
					negatives++;
					if (first) {
						firstNeg = n;
						first = false;
					} 
					lastNeg = n;
				}
				n++;
			}
			int prev = 0;
			BigInteger max = new BigInteger(String.valueOf(Long.MIN_VALUE));
			boolean start = true;
			if (zeros == 0) {
				max = new BigInteger("1");
				if (negatives % 2 == 0) {
					for (int i = 0; i < n ;i++) {
						max = max.multiply(new BigInteger(String.valueOf(vals[i])));
					}
				} else {
					boolean k = false;
					for (int i = firstNeg + 1; i < n ;i++) {
						k = true;
						max = max.multiply(new BigInteger(String.valueOf(vals[i])));
					}
					BigInteger max2 = new BigInteger("1");
					for (int i = 0; i < lastNeg; i++) {
						k = true;
						max2 = max2.multiply(new BigInteger(String.valueOf(vals[i])));
					}
					if (k) {
						if (max2.compareTo(max) > 0) {
							max = max2;
						}
					} else {
						max = new BigInteger(String.valueOf(vals[firstNeg]));
					}
					
				}
				System.out.println(max);
			} else {
				for (int i = 0; i < zeros; i++) {
					int neg = 0, firstNega = 0, lastNega = 0;
					boolean firstNegative = true;
					for (int j = prev; j < zeroPositions[i]; j++) {
						if (vals[j] < 0) {
							neg++;
							if (firstNegative) {
								firstNega = j;
								firstNegative = false;
							}
							lastNega = j;
						}
					}
					if (neg % 2 == 0) {
						BigInteger res = new BigInteger("1");
						boolean k = false;
						for (int j = prev; j < zeroPositions[i]; j++) {
							k = true;
							res = res.multiply(new BigInteger(String.valueOf(vals[j])));
						}
						if (k) {
							if (start) {
								max = res;
								start = false;
							} else {
								if (res.compareTo(max) > 0) {
									max = res;
								}
							}
						} else {
							if (max.compareTo(new BigInteger(String.valueOf(vals[prev]))) < 0) {
								max = new BigInteger(String.valueOf(vals[prev]));
							}
						}
					} else {
						BigInteger res = new BigInteger("1");
						boolean k = false;
						for (int j = firstNega + 1; j < zeroPositions[i]; j++) {
							k = true;
							res = res.multiply(new BigInteger(String.valueOf(vals[j])));
						}
						BigInteger res2 = new BigInteger("1");
						for (int j = prev; j < lastNega; j ++) {
							k = true;
							res2 = res2.multiply(new BigInteger(String.valueOf(vals[j])));
						}
						if (res.compareTo(res2) < 0) {
							res = res2;
						}
						if (k) {
							if (start) {
								max = res;
								start = false;
							} else {
								if (res.compareTo(max) > 0) {
									max = res;
								}
							}
						} else {
							if (max.compareTo(new BigInteger(String.valueOf(vals[firstNega]))) < 0) {
								max = new BigInteger(String.valueOf(vals[firstNega]));
							}
						}
					
					}
					prev = zeroPositions[i] + 1;
				}
				if (prev < n && zeros != 0) {
					int neg = 0, firstNeg1 = 0, lastNeg1 = 0;
					boolean first1 = true;
					for (int j = prev; j < n; j++) {
						if (vals[j] < 0) {
							neg++;
							if (first1) {
								firstNeg1 = j;
								first1 = false;
							}
							lastNeg1 = j;
						}
						
					}
					if (neg % 2 == 0) {
						BigInteger res = new BigInteger("1");
						for (int j = prev; j < n; j++) {
							res = res.multiply(new BigInteger(String.valueOf(vals[j])));
						}
						if (start) {
							max = res;
							start = false;
						} else {
							if (res.compareTo(max) > 0) {
								max = res;
							}
						}
					} else {
						BigInteger res = new BigInteger("1");
						boolean k = false;
						for (int j = firstNeg1 + 1; j < n; j++) {
							k = true;
							res = res.multiply(new BigInteger(String.valueOf(vals[j])));
						}
						BigInteger res2 = new BigInteger("1");
						for (int j = prev; j < lastNeg1; j ++) {
							k = true;
							res2 = res2.multiply(new BigInteger(String.valueOf(vals[j])));
						}
						if (res.compareTo(res2) < 0) {
							res = res2;
						}
						if (k) {
							if (start) {
								max = res;
								start = false;
							} else {
								if (res.compareTo(max) > 0) {
									max = res;
								}
							}
						} else {
							if (max.compareTo(new BigInteger(String.valueOf(vals[firstNeg1]))) < 0) {
								max = new BigInteger(String.valueOf(vals[firstNeg1]));
							}
						}
						
					}
				}
				if (max.compareTo(new BigInteger("0")) > 0) {
					System.out.println(max);
				} else {
					System.out.println("0");
				}
			}
			
			
			
		}
		inputScanner.close();
	}
}