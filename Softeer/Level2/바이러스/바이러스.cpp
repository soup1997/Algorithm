#include<iostream>

using namespace std;

void virus(long long& K, long long& P, long long& N) {
	long long NumOfVirus = K;
	// pow하면 범위넘어서 overflow 발생, long long 8 byte짜리 자료형 이용
	
    // overflow 방지를 위해 power 연산마다 modulus 연산 실행
	for(auto i = 1; i <= N; i++) {
		NumOfVirus = (NumOfVirus * P) % 1000000007;
	}

	cout << NumOfVirus;
}

int main(int argc, char** argv)
{
 	long long K = 0, P = 0, N = 0;
	cin >> K >> P >> N;
	virus(K, P, N);
	return 0;
}