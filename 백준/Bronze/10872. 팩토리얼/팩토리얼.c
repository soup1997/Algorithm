#include <stdio.h>
int main()
{
	int N, res = 1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		res *= N - i;
	}
	printf("%d", res);
	return 0;
}
