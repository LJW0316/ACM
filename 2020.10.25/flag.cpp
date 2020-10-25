#include <iostream>
using namespace std;

string s;
int n,m,w[100],b[100],r[100];

int check(char c)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        if (s[i] != c)
        {
            sum++;
        }
    }
    return sum;
}

int main()
{
    cin >> n >> m;
    int res = m * n;
    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        w[i] = w[i - 1] + check('W'); //计算从第1行到第i行全涂白
        b[i] = b[i - 1] + check('B');
        r[i] = r[i - 1] + check('R');
    }
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = 2; j <= n - 1; j++)
        {
            res = min(res, w[i] + b[j] - b[i] + r[n] - r[j]);
        }
        
    }
    cout << res << endl;
    return 0;
}