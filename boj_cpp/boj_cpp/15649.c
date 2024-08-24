#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_LENGTH		9

int n = 0;
int m = 0;
int visited[MAX_LENGTH];
int numbers[MAX_LENGTH];

void back_tracking(int length)
{
	if (length == m)
	{
		// Print numbers
		for (int i = 0; i < m; ++i) { printf("%d ", numbers[i]); }
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (!visited[i])
		{
			visited[i] = 1;
			numbers[length] = i;
			back_tracking(length + 1);
			visited[i] = 0;
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);

	back_tracking(0);

	return 0;
}