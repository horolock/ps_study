/*
* BOJ 1427
* Silver V
* 소트 인사이드 
*/

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[])
{
	int i = 0;
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string inp;
	std::cin >> inp;
	std::vector<int> inputVector(inp.size(), 0);

	// Fill the vector
	for (i = 0; i < inp.size(); i++)
	{
		inputVector[i] = std::stoi(inp.substr(i, 1));
	}

	for (i = 0; i < inp.length(); i++)
	{
		int maxPosition = i;

		for (int j = i + 1; j < inp.length(); j++)
		{
			// Find largest value position after current position
			if (inp[j] > inp[maxPosition]) { maxPosition = j; }
		}

		if (inp[i] < inp[maxPosition])
		{
			int temp = inp[i];
			inp[i] = inp[maxPosition];
			inp[maxPosition] = temp;
		}
	}

	for (const auto& e : inp)
	{
		std::cout << e;
	}

	return 0;
}