/*
 * Main.cpp
 *
 *  Created on: Dec 10, 2017
 *      Author: root
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
	while (true) {
		int length;
		cin >> length;
		if (length == 0) {
			break;
		}
		while (true) {
			vector<int> endPos;
			int val;
			cin >> val;
			if (val == 0) {
				break;
			}
			endPos.push_back(val);
			for (int i = 0; i < length - 1; i++) {
				val = 0;
				cin >> val;
				endPos.push_back(val);
			}
			stack<int> progress;
			int posNow = 0;
			for (int i = 0;i < length; i++) {
				int valNow = i + 1;
				progress.push(valNow);
				while (!progress.empty() && progress.top() == endPos[posNow]) {
					progress.pop();
					posNow++;
				}
			}
			if (posNow == length) {
				cout << "Yes" << endl;
			} else {
				bool yes = true;
				while (!progress.empty()) {
					if (progress.top() != endPos[posNow]) {
						yes = false;
						break;
					}
					posNow++;
					progress.pop();
				}
				if (yes) {
					cout << "Yes" << endl;
				} else {
					cout << "No" << endl;
				}
			}
		}
		cout << "\n";
	}
}

