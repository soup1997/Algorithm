#include <iostream>
#include <cmath>
void hanoi(int n, int start, int mid, int end);
using namespace std;
int main()
{
	int n;
	cin >> n;
	cout << (int)pow(2, n) - 1<< endl;
	hanoi(n, 1, 2, 3);
	return 0;
}
void hanoi(int n, int start, int mid, int end)
{
	if (n == 1)
	{
		cout << start <<" "<< end<< "\n";
	}
	else
	{
		hanoi(n - 1, start, end, mid);
		cout << start <<" "<< end<< "\n";
		hanoi(n - 1, mid, start, end);
	}
}