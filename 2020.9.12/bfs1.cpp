#include <iostream>
#include <queue>
using namespace std;

const int MAXN = 22;
struct node
{
    int x, y, t;
};

int n, m;
char maze[MAXN][MAXN]; //存储迷宫
bool vis[MAXN][MAXN];  //存储是否访问
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1}; //存储移动坐标
queue<node> que;

bool can_vis(int x, int y) //判断是否越界
{
    if (x < 0 || x >= n)
        return false;
    if (y < 0 || y >= m)
        return false;
    return true;
}

void bfs() //广度优先搜索走迷宫
{
    while (!que.empty()) //若队列不为空，继续搜素，队列为空则无解
    {
        node cur = que.front();        //取出队首元素信息
        que.pop();                     //队首出队
        if (maze[cur.x][cur.y] == 'T') //判断是否走到终点
        {
            cout << cur.t << endl;
            return;
        }
        for (int i = 0; i < 4; i++) //进行移动
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            if (!can_vis(nx, ny))
                continue; //判断是否越界
            if (maze[nx][ny] == '#')
                continue; //判断是否为墙
            if (vis[nx][ny])
                continue;                  //判断是否已访问
            vis[nx][ny] = true;            //记录当前位置已访问
            que.push({nx, ny, cur.t + 1}); //当前位置入队，时间+1
        }
    }
    cout << -1 << endl;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> maze[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (maze[i][j] == 'S')
            {
                que.push({i, j, 0}); //找到迷宫起点放入队首
                break;
            }
        }
    }
    bfs(); //广度优先搜索走迷宫
    return 0;
}