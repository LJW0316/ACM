#include <bits/stdc++.h>
using namespace std;

int n, res = 0x7fff;
int s[15],b[15];

void dfs(int i, int x, int y)
{
    if (i > n)
    {
        if (x == 1 && y == 0)
        {
            return;
        }
        res = min(res,abs(x - y));
        return;
    }
    dfs(i + 1, x * s[i], y + b[i]);
    dfs(i + 1, x, y);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i] >> b[i];
    }
    dfs(1, 1, 0);
    cout << res << endl;
    return 0;
}