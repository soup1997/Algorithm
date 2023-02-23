#include <iostream>
using namespace std;
int main()
{
	int N, K, cnt = 0;
	cin >> N >> K;
	int* money = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> money[i];
	}
	for (int j = N - 1 ; j >= 0 ; j--)
	{
		if (K >= money[j])
		{
			cnt += K / money[j];
			K %= money[j];
		}
		if (K == 0)
		{
			break;
		}
	}
	delete[] money;
	cout << cnt;
	return 0;
}