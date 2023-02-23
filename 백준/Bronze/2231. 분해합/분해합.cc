#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int number, cnt = 0, sum = 0;
	char str1[10];
	cin >> number;
	int temp = number;
	while (temp)
	{
		temp /= 10;
		cnt++;
	}
	for (int i = number - (cnt * 9) ; i <= number; i++)
	{
		sum = i;
		sprintf(str1, "%d", i);
		for (int j = 0; j < strlen(str1); j++)
		{
			sum = sum + (str1[j] - '0');
		}
		if (sum == number)
		{
			cout << i << endl;
			return 0;
		}
	}
	cout << '0' << endl;
	return 0;
}