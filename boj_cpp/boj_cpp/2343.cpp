#include <iostream>
#include <vector>


int main(void)
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	/*
	* Variables
	*/
	int lessonCount = 0;
	int blurayCount = 0;
	int startValue = 0;
	int endValue = 0;

	/*
	* Input Lesson Count and Bluray Count
	*/
	std::cin >> lessonCount >> blurayCount;

	std::vector<int> lessonTable(lessonCount);

	/*
	* Get Lesson data and find start, end value
	* Start value : Maximum lesson value
	* End value : Sum every lesson values
	*/
	for (int i = 0; i < lessonCount; i++) {
		std::cin >> lessonTable[i];

		if (startValue < lessonTable[i]) { startValue = lessonTable[i]; }

		endValue = endValue + lessonTable[i];
	} 

	/*
	* Search
	*/
	while (startValue <= endValue) {
		int middle = (startValue + endValue) / 2;
		int sum = 0;
		int count = 0;

		for (int i = 0; i < lessonCount; i++) {
			if (sum + lessonTable[i] > middle) {
				count++;
				sum = 0;
			}
			sum = sum + lessonTable[i];
		}

		if (sum != 0) { count++; }

		if (count > blurayCount) {
			startValue = middle + 1;
		}
		else {
			endValue = middle - 1;
		}
	}

	std::cout << startValue << "\n";

	return 0;
}