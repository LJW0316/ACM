#include <iostream>
#include <cmath>
using namespace std;

int a[50005];
int num[1000005] = {0};

int main()
{
    int t, n, sum = 0, dis = 0, k;

    cin >> t >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] >= 0)
        {
            num[a[i]] = 1;
        }
        else
        {
            num[-a[i]] = -1;
        }
    }
    k = 0;
    for (int i = 0; i <= 1000002; i++)
    {
        if (num[i] != 0)
        {
            dis = abs(num[i] * i - num[k] * k);
            if (t - dis >= 0)
            {
                sum++;
                t -= dis;
                k = i;
            }
            else
            {
                break;
            }
        }
    }
    cout << sum << endl;
    return 0;
}