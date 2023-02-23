#include <stdio.h>
int main()
{
	int hour = 0, min = 0;
	scanf("%d %d", &hour, &min);
	if (min < 45)
	{
		min = (min + 60) - 45;
		if (hour == 0)
		{
			hour = (hour - 1) + 24;
		}
		else
		{
			hour = hour - 1;
		}
	}
	else
	{
		min = min - 45;
	}
	printf("%d %d", hour, min);
}