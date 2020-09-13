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

bool can_vis(int x, int y) //判断目前点是否越界
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

void dfs(int x, int y) //深度优先搜素倒退求路径
{
    int temp = from[x][y];
    if (x != 0 || y != 0)
    {
        dfs(x - dx[temp], y - dy[temp]);
    }
    cout << "(" << x << ", " << y << ")" << endl;
}

void bfs() //广度优先搜素走迷宫
{
    while (!que.empty())
    {
        node cur = que.front(); //获取队首信息
        node temp;
        que.pop();                    //出队列
        if (cur.x == 4 && cur.y == 4) //到达终点，结束搜素
        {
            dfs(cur.x, cur.y);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i]; //上下左右进行移动
            if (!can_vis(nx, ny))
                continue; //判断是否越界
            if (maze[nx][ny] == 1)
                continue; //判断是否是墙
            if (vis[nx][ny])
                continue; //判断是否已被访问
            vis[nx][ny] = true;
            temp.x = nx;
            temp.y = ny;
            temp.t = cur.t + 1; //时间+1
            que.push(temp);     //新节点入队
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
    que.push(a); //从(0,0)点开始广度优先搜索
    bfs();
    return 0;
}
