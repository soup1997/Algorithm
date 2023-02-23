#include <stdio.h>
int place_value(int x);
int main()
{
	int N = 0;
	int count = 0;
	int res;
	scanf("%d", &N);
	for (int X = 1; X <= N; X++)
	{
		if (X / 100 != 0) // 세자리 수
		{
			res = place_value(X);
			if (res == 1)
			{
				count++;
			}
			else
			{
				continue;
			}
		}
		else if (X >= 10 && X < 100) // 두자리 수
		{
			count++; // 두자리 수의 경우 항상 한수
		}
		else if (X < 10 ) // 한자리 수
		{
			count++;  // 한자리 수의 경우도 항상 한수 이므로 카운트
		}

	}
	printf("%d", count);
	return 0;
}
int place_value(int x)
{
	int a, b, c; // 백의 자리, 십의 자리, 일의 자리
	a = x / 100;
	b = (x % 100) / 10;
	c = (x % 100) % 10;
	if (b - c == a - b)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}