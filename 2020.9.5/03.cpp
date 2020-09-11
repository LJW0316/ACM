#include <bits/stdc++.h>
using namespace std;

int main()
{
    int f[1005];
    int n;
    cin >> n;
    f[0] = 0;
    f[1] = 1;
    f[2] = 3;
    for (int i = 3; i <= n; i++)
    {
        f[i] = (f[i - 1] + 2 * f[i - 2]) % 12345;
    }
    cout << f[n] << endl;
    return 0;
}
