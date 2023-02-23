#include <iostream>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int* weight = new int[N];
	int* height = new int[N];
	int* rank = new int[N];
	int cnt;
	for (int i = 0; i < N; i++)
	{
		cin >> weight[i] >> height[i];
	}
	for (int i = 0; i < N; i++)
	{
		cnt = 0;
		for (int j = 0; j < N; j++) 
 		{
			if (weight[i] < weight[j] && height[i] < height[j])
			{
				cnt++;
			}
		}
		rank[i] = cnt + 1;
	}
	for (int i = 0; i < N; i++)
	{
		cout << rank[i] << " ";
	}
	delete[] weight;
	delete[] height;
	delete[] rank;
	return 0;
}