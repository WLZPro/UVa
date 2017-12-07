/*;
 * Main.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: root
 */

/*#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <limits>

int main() {

	while (true) {
		std::string input = "";
		std::stringstream mystream;
		std::getline(std::cin,input);
		if (input.length() == 0) {
			break;
		}

		mystream << input;
		int participants, budget, hotels ,weeks;
		mystream >> participants >> budget >> hotels >> weeks;
		std::vector<int> hotelCosts(hotels);
		std::vector< std::vector<int> > freeBeds(hotels, std::vector<int>(weeks));
		for (int i = 0; i < hotels; i++) {
			int cost;
			std::getline(std::cin,input);
			std::stringstream mystream2;
			mystream2 << input;
			mystream2 >> cost;
			hotelCosts[i] = cost;
			std::stringstream mystream3;
			std::getline(std::cin,input);
			mystream3 << input;
			for (int j=0;j<weeks;j++) {
				mystream3 >> freeBeds[i][j];
			}
		}
		int min = std::numeric_limits<int>::max();
		for (int i = 0; i < hotels; ++i) {
			if (hotelCosts[i] < min) {
				if (hotelCosts[i] * participants <= budget) {
					for (int j = 0; j < weeks; ++j) {
						if (freeBeds[i][j] >= participants) {
							min = hotelCosts[i];
							break;
						}
					}
				}
			}
		}
		if (min != std::numeric_limits<int>::max()) {
			std::cout << min * participants << std::endl;
		} else {
			std::cout << "stay home" << std::endl;
		}
	}

	return 0;
}*/
