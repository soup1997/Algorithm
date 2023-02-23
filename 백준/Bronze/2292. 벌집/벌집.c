#include <stdio.h>
int main(void)
{
	int N, range = 1, cnt = 1;
	scanf("%d", &N);
	while(cnt < N)
	{
		cnt += 6 * range;
		range++;
	}
	printf("%d", range);
}