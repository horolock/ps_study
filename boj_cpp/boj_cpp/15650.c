/*
* 15650
* Silver3
* N°ú M(2)
*/

#define _CRT_SECURE_NO_WARNINGS

#define MAX_LENGTH 9

#include <stdio.h>

int n, m;
int numbers[MAX_LENGTH];

void back_tracking(int current, int length)
{
	if (length == m)
	{
		// Do print numbers
		for (int i = 0; i < length; ++i) { printf("%d ", numbers[i]); }
		printf("\n");
		return;
	}

	if (current + 1 > n) { return; }

	for (int i = current + 1; i <= n; ++i)
	{
		numbers[length] = i;
		back_tracking(i, length + 1);
	}
}

int main(int argc, char* argv[])
{
	scanf("%d %d", &n, &m);

	back_tracking(0, 0);

	return 0;
}
