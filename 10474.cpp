/*
 * Main.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: root
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
int main() {
	int currentCase = 1;
	while (true) {
		int queries, marbles;
		std::cin >> marbles >> queries;
		if (queries == 0 && marbles == 0) {
			break;
		}
		std::vector<int> marblesVals(marbles);
		std::vector<int> querieVals(queries);
		for (int i = 0; i < marbles; i++) {
			int val;
			std::cin >> val;
			marblesVals[i] = val;
		}
		std::sort(std::begin(marblesVals), std::end(marblesVals));
		for (int i = 0; i < queries; i++) {
			int val;
			std::cin >> val;
			querieVals[i] = val;
		}
		std::cout << "CASE# " << currentCase << ":" << std::endl;
		for (int i = 0; i < queries; i++) {
			int val = querieVals[i];
			bool found = false;
			int lo = 0, hi = marbles - 1, mid;
			while (lo <= hi) {
				mid = (lo + hi) / 2;
				if (marblesVals[mid] == val) {
					found = true;
					while (marblesVals[mid] == val && mid > 0) {
						mid--;
					}
					if (mid == 0 && marblesVals[0] == val) {
						mid = 0;
					} else if (mid == 0) {
						mid = 1;
					} else {
						++mid;
					}
					break;
				} else if (marblesVals[mid] < val) {
					lo = mid + 1;
				} else {
					hi = mid - 1;
				}
			}
			if (!found) {
				std::cout << val << " not found" << std::endl;
			} else {
				std::cout << val << " found at " << mid + 1<< std::endl;
			}
		}
		currentCase++;
	}
	return 0;
}

