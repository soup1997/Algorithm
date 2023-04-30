#include<iostream>
#include<vector>

using namespace std;

double get_average(const vector<int>& S, int& A, int& B) {
	int s_index = A - 1;
	int number = B - s_index;
	double average = 0;

	for(auto i = s_index; i < B; i++) {
		average += static_cast<double>(S[i]);
	}

	return average / number;
}

void print_result(const vector<double>& result) {
	cout.setf(ios::fixed);
	cout.precision(2);
	
	for (auto score: result) {
		cout << score << endl;
	}
}

int main(int argc, char** argv)
{
	int N, K;
	int score;
	vector<int> S;
	int A, B;
	vector<double> result;

	cin >> N >> K;
	for (auto i = 0; i < N; i++) {
		cin >> score;
		S.push_back(score);
	}

	for(auto i = 0; i < K; i++) {
		cin >> A >> B;
		result.push_back(get_average(S, A, B));
	}

	print_result(result);

	return 0;
}