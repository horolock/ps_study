#include <iostream>
#include <queue>

using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N;
	priority_queue<int> positiveNumberQueue;
	priority_queue<int, vector<int>, greater<int>> negativeNumberQueue;
	int numberOfOne = 0;
	int numberOfZero = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		int inp;

		cin >> inp;

		if (inp > 1) { positiveNumberQueue.push(inp); }
		else if (inp == 1) { numberOfOne++; }
		else if (inp == 0) { numberOfZero++; }
		else { negativeNumberQueue.push(inp); }
	}

	int sum = 0;

	while (positiveNumberQueue.size() > 1) {
		int first = positiveNumberQueue.top();

		positiveNumberQueue.pop();

		int second = positiveNumberQueue.top();

		positiveNumberQueue.pop();

		sum = sum + (first * second);
	}

	if (!positiveNumberQueue.empty()) {
		sum = sum + positiveNumberQueue.top();
		positiveNumberQueue.pop();
	}

	while (negativeNumberQueue.size() > 1) {
		int first = negativeNumberQueue.top();
		negativeNumberQueue.pop();
		int second = negativeNumberQueue.top();
		negativeNumberQueue.pop();

		sum = sum + (first * second);
	}

	if (!negativeNumberQueue.empty()) {
		if (numberOfZero == 0) {
			sum = sum + negativeNumberQueue.top();
			negativeNumberQueue.pop();
		}
	}

	sum = sum + numberOfOne;

	cout << sum << "\n";

	return 0;
}