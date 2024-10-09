#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
using vi = vector<int>;

vector<int> x;
vector<int> y;
int n;
int k;

int calc(int p1, int p2, int p3) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, min({ abs(x[i] - x[p1]) + abs(y[i] - y[p1]), abs(x[i] - x[p2]) + abs(y[i] - y[p2]), abs(x[i] - x[p3]) + abs(y[i] - y[p3]) }));
    }
    return ans;
}

int main()
{
    cin >> n >> k;
    vector<int> xx(n);
    vector<int> yy(n);
    x = xx;
    y = yy;

    int ans = 99999999;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        x[i] = a;
        y[i] = b;
    }

    if (k == 1) {
        for (int i = 0; i < n; ++i)
        {
            ans = min(ans, calc(i, i, i));
        }
    }
    else if (k == 2) {
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                ans = min(ans, calc(i, j, j));
            }
        }
    }
    else if (k == 3) {
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                for (int k = j; k < n; ++k) {
                    ans = min(ans, calc(i, j, k));
                }
            }
        }
    }
    cout << ans << '\n';

    return 0;
}