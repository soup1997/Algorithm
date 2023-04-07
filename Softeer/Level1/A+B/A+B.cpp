#include<iostream>

using namespace std;

int sum(int x, int y, int index) {
	cout << "Case #" << index+1 << ":" << " " << x + y << endl;
}

int main(int argc, char** argv)
{
	int num, x, y;
	cin >> num;

	for(auto i = 0; i < num; i++) {
		cin >> x >> y;
		sum(x, y, i);
	}
	return 0;
}