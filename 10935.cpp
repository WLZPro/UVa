/*
 * Main.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: root
 */
#include <iostream>
#include <vector>
using namespace std;
int main() {
	while (true) {
		int val;
		cin >> val;
		if (val == 0) {
			break;
		}
		vector<int> throwedCards;
		vector<int> cards(val);
		int remainingCards = 0;
		int cardsVal = val;
		for (int i = 0;i < val; i++) {
			cards[i] = i + 1;
		}
		while (true) {
			if (cardsVal == 1) {
				break;
			}
			throwedCards.push_back(cards[remainingCards]);
			cards[remainingCards] = -1;
			remainingCards++;
			int g = cards[remainingCards];
			cards[remainingCards] = -1;
			cards.push_back(g);
			remainingCards++;
			cardsVal--;
		}
		cout << "Discarded cards:";
		for (int i = 0; i < val - 1; i++) {
			cout << " " <<throwedCards[i];
			if (i < val - 2) {
				cout << ",";
			}
		}
		cout << "\nRemaining card: " << cards[remainingCards] << endl;
	}
	return 0;
}


