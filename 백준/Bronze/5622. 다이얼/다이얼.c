#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[16];
	int num, sum = 0;
	gets(str);
	for (int i = 0; i < strlen(str); i++)
	{
		switch (str[i] % 'A')
		{
		case 0:
		case 1:
		case 2:
			num = 2;
			break;
		case 3:
		case 4:
		case 5:
			num = 3;
			break;
		case 6:
		case 7:
		case 8:
			num = 4;
			break;
		case 9:
		case 10:
		case 11:
			num = 5;
			break;
		case 12:
		case 13:
		case 14:
			num = 6;
			break;
		case 15:
		case 16:
		case 17:
		case 18:
			num = 7;
			break;
		case 19:
		case 20:
		case 21:
			num = 8;
			break;
		case 22:
		case 23:
		case 24:
		case 25:
			num = 9;
			break;
		}
		sum += num;
	}
	printf("%d", sum + strlen(str));
	return 0;
}