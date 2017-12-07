/*
 * Main.cpp
 *
 *  Created on: Nov 30, 2017
 *      Author: root
 */
/*#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;
int main() {
	int availableBooks;
	while (cin >> availableBooks) {
		vector<int> bookPrices(availableBooks);
		for (int i = 0; i < availableBooks; ++i) {
			cin >> bookPrices[i];
		}
		sort(begin(bookPrices), end(bookPrices));
		int money;
		cin >> money;
		int i, j;
		vector<int> iv(availableBooks);
		vector<int> jv(availableBooks);
		int h = 0;
		for (int i = 0; i < availableBooks; i++) {
			int lo = 0, hi = availableBooks - 1,mid;
			while (lo <= hi){
				mid = (lo + hi) / 2;
				if (bookPrices[i] + bookPrices[mid] > money) {
					hi = mid - 1;
				} else if (bookPrices[i] + bookPrices[mid] < money) {
					lo = mid + 1;
				} else {
					if (i != mid) {
						iv[h] = bookPrices[i];
						jv[h] = bookPrices[mid];
						++h;
					}
					break;
				}
			}
		}
		int min = numeric_limits<int>::max();
		int minPos;
		for (int i = 0; i < h; ++i) {
			if (abs(iv[i] - jv[i]) < min) {
				min = abs(iv[i] - jv[i]);
				minPos = i;
			}
		}
		if (jv[minPos] < iv[minPos]) {
			swap(jv[minPos],iv[minPos]);
		}
		cout << "Peter should buy books whose prices are " << iv[minPos] <<" and " <<jv[minPos] << ".\n" <<endl;
	}
	return 0;
}*/


