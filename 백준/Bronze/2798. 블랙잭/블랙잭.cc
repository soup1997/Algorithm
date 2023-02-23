#include <iostream> 
using namespace std;
int main(void)
{
	int N, M, i, j, k;
	int sum = 0, max = 0;
	cin >> N >> M;
	int* card = new int[N];
	for (i = 0; i < N; i++) //card의 숫자를 받는 반복문
	{
		cin >> card[i];
	}
	for (i = 0; i < N - 2; i++) // N개의 카드중 3장의 합을 모두 구하는 반복문
	{
		for (j = i + 1; j < N - 1; j++)
		{
			for (k = j + 1; k < N; k++)
			{
				sum = card[i] + card[j] + card[k];
				if (sum <= M && sum > max)
				{
					max = sum;
				}
			}
		}
	}
	cout << max << endl;
	delete card;
	return 0;
}