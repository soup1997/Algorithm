#include <iostream>
using namespace std;
int main()
{
	int N;
	int temp;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		for (int j = 0; j < (N - 1) - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int k = 0; k < N; k++)
	{
		cout << arr[k] << endl;
	}
	delete[] arr;
	return 0;
}