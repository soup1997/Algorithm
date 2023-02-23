#include <stdio.h>
int main()
{
	int N, X;
	int a; // A 수열의 원소
	scanf("%d %d", &N, &X);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &a);
		if (a < X)
		{
			printf("%d ", a);
		}
	}
	return 0;
}
