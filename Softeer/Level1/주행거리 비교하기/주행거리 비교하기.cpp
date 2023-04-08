<<<<<<< HEAD
#include<iostream>
#include<string>

using namespace std;

int calc_time(string& start, string& end) {
	int StartHour = stoi(start.substr(0, 2));
	int StartMin = stoi(start.substr(3, 2));

	int EndHour = stoi(end.substr(0, 2));
	int EndMin = stoi(end.substr(3, 2));

	int TotalHour = EndHour - StartHour;
	int TotalMin = 0;
	
	if (StartMin < EndMin) {
		TotalMin = EndMin - StartMin;
	}

	else if(StartMin > EndMin) {
		TotalMin = (60 - StartMin) + EndMin;
		TotalHour--;
	}

	else;

	return (TotalHour) * 60 + TotalMin;
}

int main(int argc, char** argv)
{
	string start, end;
	int res = 0;

	for(auto i = 0; i < 5; i++) {
		cin >> start >> end;
		res += calc_time(start, end);
	}

	cout << res;

	return 0;
=======
#include <iostream>

using namespace std;

bool comparator(int A, int B)
{
    if (A > B)
    {
        cout << "A";
    }

    else if (A < B)
    {
        cout << "B";
    }

    else
        cout << "same";
}
int main(int argc, char **argv)
{
    int A, B;
    cin >> A >> B;
    comparator(A, B);
    return 0;
>>>>>>> 89765b17f8cd64177611a3d9856af349a7ef2d58
}