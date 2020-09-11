#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, f[45];
    cin >> n;
    f[1] = 2;
    f[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        f[i] = f[i - 1] + f[i - 2];
    }
    cout << f[n];
    return 0;
}