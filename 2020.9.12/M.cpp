#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 25;

struct node
{
    int x, y, t, d;
};

int maze[maxn][maxn];
bool vis[maxn][maxn][maxn];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
queue<node> que;
int n, m, k;

bool can_vis(int x, int y)
{
    if (x < 0 || x >= n)
    {
        return false;
    }
    if (y < 0 || y >= m)
    {
        return false;
    }
    return true;
}

void bfs()
{
    memset(vis, false, sizeof(vis));
    vis[0][0][0] = true;
    while (!que.empty())
    {
        node cur = que.front();
        que.pop();
        if (cur.x == n && cur.y == m)
        {
            cout << cur.t << endl;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (can_vis(nx,ny))
            {
                int temp;
                if (maze[nx][ny])
                {
                    temp = cur.d + 1;
                }
                else
                {
                    temp = 0;
                }
                if (temp <= k && !vis[nx][ny][temp])
                {
                    que.push({nx, ny, cur.t + 1, temp});
                    vis[nx][ny][temp] = true;
                }
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    int r;
    cin >> r;
    while (r > 0)
    {
        r--;
        cin >> n >> m >> k;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> maze[i][j];
            }
        }
        que.push({0, 0, 0, 0});
        bfs();
    }
    return 0;
}