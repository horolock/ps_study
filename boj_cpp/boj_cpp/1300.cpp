#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
long maxNumber = 0;
long k = 0;

long gStart = 0, gEnd = 0;
long answer = 0;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n >> k;

	gStart = 1;
	gEnd = k;

	while (gStart <= gEnd) {
		long middle = (gStart + gEnd) / 2;
		long count = 0;

		/* Counting smaller than middle number */
		for (int i = 1; i <= n; ++i) { count += min(middle / i, (long)n); }

		if (count < k) { gStart = middle + 1; }
		else {
			answer = middle;
			gEnd = middle - 1;
		}
	}

	cout << answer << '\n';

	return 0;
}
