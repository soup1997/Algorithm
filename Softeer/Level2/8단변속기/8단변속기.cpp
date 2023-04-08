#include<iostream>
#include<vector>
#include<string>

using namespace std;

void check(vector<int>& v) {
	string result;
	for(auto i= 0; i < v.size()-1; i++) {
		if(v[i+1] - v[i] == 1) {
			result = "ascending";
		}

		else if(v[i+1] - v[i] == -1) {
			result = "descending";
		}

		else {
			result = "mixed";
			break;
		}
	}

	cout << result;
}

int main(int argc, char** argv)
{
	vector<int> transmission;
	int gear = 0;

	for(auto i = 0; i < 8; i++) {
		cin >> gear;
		transmission.push_back(gear);
	}
	
	check(transmission);

	return 0;
}