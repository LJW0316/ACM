#include <bits/stdc++.h>
using namespace std;

struct node
{
    int x, y, w, d;
};
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int maze[25][25];
int n, m, k;
bool vis[25][25][25]; //记录是否访问过及跳过障碍数

void bfs() //广度优先搜素求最短路径
{
    memset(vis, false, sizeof(vis));
    queue<node> que;        //每组重新定义队列，防止互相影响
    que.push({1, 1, 0, 0}); //起点入队
    vis[1][1][0] = true;    //记录起点已被访问，跳过0个障碍
    while (!que.empty())    //若队列不为空，继续搜索
    {
        node cur = que.front();       //获取队首信息
        que.pop();                    //队首出队
        if (cur.x == n && cur.y == m) //到达终点，输出，结束搜素
        {
            cout << cur.w << endl;
            return;
        }
        for (int i = 0; i < 4; i++) //进行移动
        {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];                     //记录移动后坐标
            if (nx > 0 && ny > 0 && nx <= n && ny <= m) //移动后在边界内部
            {
                int temp;         //记录需要跳过的墙
                if (maze[nx][ny]) //移动后为墙，需要跳过的墙+1
                    temp = cur.d + 1;
                else
                    temp = 0;                        //移动后不是墙，需要跳过的墙为0
                if (temp <= k && !vis[nx][ny][temp]) //若需要跳过的墙小于k，且移动后为访问
                {
                    que.push({nx, ny, cur.w + 1, temp}); //新元素入队
                    vis[nx][ny][temp] = true;            //新位置已访问
                }
            }
        }
    }
    cout << -1 << endl; //无法走出
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> maze[i][j];
        bfs(); //广度优先搜素求解
    }
    return 0;
}
