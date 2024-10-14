#include <iostream>
#include <string>

int main(int argc, char* argv[]) 
{
	std::string inp;
	std::string newString;
	int cycleLength = 0;

	std::cin >> inp;

	if (inp.length() == 1) {
		inp = "0" + inp;
	}

	newString = inp;

	for (;;) {
		int lhs = 0;
		int rhs = 0;
		int res = 0;

		lhs = (int)(newString[0] - '0');
		rhs = (int)(newString[1] - '0');
		
		res = lhs + rhs;

		if (res >= 10) {
			newString = std::to_string(rhs) + std::to_string(res % 10);
		}
		else {
			newString = std::to_string(rhs) + std::to_string(res);
		}

		cycleLength++;

		if (newString == inp) {
			std::cout << cycleLength;
			break;
		}
	}

	return 0;
}