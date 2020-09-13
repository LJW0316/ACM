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
        while (n > 3) //人数大于四人情况，借助最快2人带最慢2人过河，最快2人回来
        {
            res += min(2 * a[0] + a[n - 1] + a[n - 2], 2 * a[1] + a[0] + a[n - 1]); //有两种策略：最快a的带最慢和次慢的c, d的两个人过河，时间为c + a + d + a，或者最快a的和次块b的两个先过河，然后最快的回来，再让最慢的和次慢的c, d两个人过河，然后次慢的回来，时间为b + a + d + b，每次过河取这两种策略中最快的那个
            n -= 2;
        }
        if (n == 1 || n == 3) //只有1或3人的时候：时间为所有人过河的时间和
        {
            for (int j = 0; j < n; j++)
            {
                res += a[j];
            }
        }
        else //只有2人时时间为两人中间慢者
        {
            res += a[1];
        }
        cout << res << endl;
    }
    return 0;
}
