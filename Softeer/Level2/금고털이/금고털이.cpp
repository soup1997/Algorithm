// 굳이 따로 금속을 얼마나 넣어야 하는지 갯수를 구할 필요가 없다.
// 금속이 N개 주어져있으면 그대로 넣으면 되고, 나머진 잘라서 넣으면 된다.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef pair<int, int> metal;

bool compare(metal a, metal b) {
	return a.second > b.second;
}

void answer(const vector<metal>&bag, int W) {
	int total_price = 0;

	for(const auto& i: bag) {
		
		if(W >= i.first) {
			total_price += (i.first * i.second);
			W -= i.first;
		}

		else {
			total_price += W * i.second;
			break;
		}
	}
	cout << total_price;
}

int main(int argc, char** argv)
{
	int W, N;
	int weight, price;
	vector<metal> bag;

	cin >> W >> N;

	for(auto i = 0; i < N; i++) {
		cin.ignore();
		cin >> weight >> price;
		bag.push_back(metal(weight, price));
	}
	sort(bag.begin(), bag.end(), compare);

	answer(bag, W);
	return 0;
}