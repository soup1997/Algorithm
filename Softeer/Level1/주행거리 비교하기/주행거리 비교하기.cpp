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

}
