/*
 * Main.cpp
 *
 *  Created on: Dec 2, 2017
 *      Author: root
 */

#include <vector>
#include <iostream>
using namespace std;

int main() {
	int cases;
	cin >> cases;
	for (int i = 0; i < cases; i++) {
		int ferryLength, cars;
		cin >> ferryLength >> cars;
		ferryLength *= 100;
		vector<int> left(cars);
		vector<int> right(cars);
		int h = 0, k = 0;
		for (int j = 0; j < cars; j++) {
			int carLength;
			bool side;
			string input;
			cin >> carLength >> input;
			if (input.compare("right") == 0) {
				right[k++] = carLength;
			} else if (input.compare("left") == 0) {
				left[h++] = carLength;
			}
		}
		int count = 0;
		while (true) {
			int f = 0;
			if (h > 0) {
				do {
					f += left[--h];
					if (h <= 0) {
						break;
					}
				} while (f + left[h - 1] <= ferryLength);
			}
			count++;
			if (h <= 0 && k <= 0) {
				break;
			}
			f = 0;
			if (k > 0) {
				do {
					f += right[--k];
					if (k <= 0) {
						break;
					}
				} while (f + right[k - 1] <= ferryLength);

			}
			count++;
			if (h <= 0 && k <= 0) {
				break;
			}
		}
		cout << count << endl;
	}
}
