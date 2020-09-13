#include <iostream>
using namespace std;

const int maxn = 110;

int cnt, n, m;
bool vis[maxn][maxn];
char a[maxn][maxn];
int dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[8] = {0, 0, 1, -1, -1, 1, 1, -1}; //记录移动八个方向

void dfs(int x, int y) //广度优先搜素搜素油田数量
{
    if (vis[x][y])
        return;
    cnt++;
    vis[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        if (x + dx[i] < 0 || x + dx[i] >= n)
            continue;
        if (y + dy[i] < 0 || y + dy[i] >= m)
            continue;
        if (a[x + dx[i]][y + dy[i]] == '*')
            continue;
        dfs(x + dx[i], y + dy[i]);
    }
}

int main()
{
    int ans = 0;
    cin >> n >> m;
    while (n != 0 && m != 0)
    {
        ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                vis[i][j] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '@')
                {
                    cnt = 0;
                    dfs(i, j);
                    if (cnt > 0)
                    {
                        ans++;
                    }
                }
            }
        }
        cout << ans << endl;
        cin >> n >> m;
    }
    return 0;
}
