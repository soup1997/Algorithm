// 3단계까지 갯수를 파악해보고 패턴을 파악하고 풀면 된다
#include<iostream>
#include<cmath>

using namespace std;

void point_cnt(int N) {
	int point = 0;
	point = 1 + pow(2, N);
	point = point * point;
	
	cout << point;
}
int main(int argc, char** argv)
{
	int N = 0;
	cin >> N;
	point_cnt(N);
	return 0;
}