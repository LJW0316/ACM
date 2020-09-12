#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 5;

struct node
{
    int x, y, t;
};

queue<node> que;
int maze[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int from[MAXN][MAXN];

bool can_vis(int x, int y)
{
    if (x < 0 || x >= MAXN)
    {
        return false;
    }
    if (y < 0 || y >= MAXN)
    {
        return false;
    }
    return true;
}

void dfs(int x, int y)
{
    int temp = from[x][y];
    if (x != 0 || y != 0)
    {

        dfs(x - dx[temp], y - dy[temp]);
    }
    cout << "(" << x << ", " << y << ")" << endl;
}

void bfs()
{
    while (!que.empty())
    {
        node cur = que.front();
        node temp;
        que.pop();
        if (cur.x == 4 && cur.y == 4)
        {
            // cout << cur.t << endl;
            dfs(cur.x, cur.y);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (!can_vis(nx, ny))
                continue;
            if (maze[nx][ny] == 1)
                continue;
            if (vis[nx][ny])
                continue;
            vis[nx][ny] = true;
            temp.x = nx;
            temp.y = ny;
            temp.t = cur.t + 1;
            que.push(temp);
            from[nx][ny] = i;
        }
    }
    cout << -1 << endl;
}

int main()
{
    for (int i = 0; i < MAXN; i++)
    {
        for (int j = 0; j < MAXN; j++)
        {
            cin >> maze[i][j];
        }
    }
    node a;
    a.x = 0;
    a.y = 0;
    a.t = 0;
    que.push(a);
    bfs();
    return 0;
}
