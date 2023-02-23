#include <stdio.h>
int main()
{
	int n;
	int c = 0, a = 0, b = 1;
	scanf("%d", &n);
	if (n == 0)
	{
		printf("%d", 0);
	}
	else if (n == 1)
	{
		printf("%d", 1);
	}
	else
	{
		for (int i = 2;i <= n; i++)
		{
			c = a + b;
			a = b;
			b = c;
		}
		printf("%d", c);
	}
	return 0;
}