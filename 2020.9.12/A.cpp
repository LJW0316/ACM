#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int turn, n, a[1005], res = 0, x, y;
    cin >> turn;
    for (int i = 0; i < turn; i++)
    {
        res = 0;
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
        }
        sort(a, a + n);
        while (n > 3)
        {
            res += min(2 * a[0] + a[n - 1] + a[n - 2], 2 * a[1] + a[0] + a[n - 1]);
            n -= 2;
        }
        if (n == 1 || n == 3)
        {
            for (int j = 0; j < n; j++)
            {
                res += a[j];
            }
        }
        else
        {
            res += a[1];
        }
        cout << res << endl;
    }
    return 0;
}
