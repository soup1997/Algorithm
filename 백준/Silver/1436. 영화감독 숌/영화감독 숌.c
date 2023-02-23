// 666 1666 2666 3666 4666 5666 6660 6661 6662 6663 6664 6665 6666 6667 6668 6669 7666 8666 9666 10666 11666 12666 13666 14666 15666 16660 16661...
#include <stdio.h>
int main(void)
{
	int i, number = 0, cnt = 0;
	char temp[10];
	scanf("%d", &number);
	for (i = 665;; i++)
	{
		sprintf(temp,"%d", i);
		for (int j = 0; j < 10; j++)
		{
			if (temp[j] == '6' && temp[j + 1] == '6' && temp[j + 2] == '6')
			{
				cnt++;
				if (number == cnt)
				{
					printf("%s", temp);
					return 0;
				}
				else
				{
					break;
				}
			}
		}
	}
	return 0;
}