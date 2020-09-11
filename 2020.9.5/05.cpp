#include <bits/stdc++.h>
using namespace std;
int a[100002][2];
int dist(int x, int y)
{
    return abs(a[x][0] - a[y][0]) + abs(a[x][1] - a[y][1]);
}
int main()
{
    int n, sum = 0, ans;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i = 2; i <= n; i++)
    {
        sum = sum + dist(i, i - 1);
    }
    ans = sum;
    for (int i = 2; i < n; i++)
    {
        ans = min(ans, sum - dist(i, i - 1) - dist(i + 1, i) + dist(i - 1, i + 1));
    }
    cout << ans << endl;
    return 0;
}