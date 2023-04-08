#include<iostream>
<<<<<<< HEAD
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> metal;

//compare가 false이면 swap한다
bool compare(metal a, metal b) {
	if (a.second < b.second) {
		return true;
	}

	else {
		return false;
	}
}

void calc_price(vector<metal> bag, int& W) {
	int price = 0;

	for(auto i: bag) {
		if(W >= i.first) {
			price += (W / i.first) * (i.first * i.second);
			W -= (W / i.first) * i.first;
		}

		else {
			price += (W % i.first) * i.second;
			W -= (W % i.first);
		}
	}

	cout << price;
=======

using namespace std;

int sum(int x, int y, int index) {
	cout << "Case #" << index+1 << ":" << " " << x + y << endl;
>>>>>>> 89765b17f8cd64177611a3d9856af349a7ef2d58
}

int main(int argc, char** argv)
{
<<<<<<< HEAD
	int W, N;
	int weight, price;
	vector<metal> bag;

	cin >> W >> N;

	for(auto i = 0; i < N; i++) {
		cin >> weight >> price;
		bag.push_back(make_pair(weight, price));
	}

	sort(bag.begin(), bag.end(), compare);
	calc_price(bag, W);
=======
	int num, x, y;
	cin >> num;

	for(auto i = 0; i < num; i++) {
		cin >> x >> y;
		sum(x, y, i);
	}
>>>>>>> 89765b17f8cd64177611a3d9856af349a7ef2d58
	return 0;
}