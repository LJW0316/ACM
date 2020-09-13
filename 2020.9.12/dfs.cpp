#include <iostream>
using namespace std;

const int MAXN = 110;

int cnt, n, m;
bool vis[MAXN][MAXN]; //判断是否访问数组
int a[MAXN][MAXN];    //存储地图信息数组
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1}; //进行位移

void dfs(int x, int y) //广度优先搜素进行遍历
{
    if (vis[x][y]) //如果该节点已被访问，则结束递归
        return;
    cnt++;
    vis[x][y] = true;           //记录当前节点已访问
    for (int i = 0; i < 4; i++) //进行移动
    {
        int nx = x + dx[i];
        int ny = y + dy[i]; //记录移动后坐标
        if (nx < 0 || nx > n)
            continue;
        if (ny < 0 || ny > m)
            continue;       //判断是否越界
        if (a[nx][ny] == 0) //判断是否为0
            continue;
        dfs(nx, ny); //递归搜素
    }
}

int main()
{
    int res = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j]) //寻找1的点进行深度优先搜索
            {
                cnt = 0; //用于记录当前区块相连1的个数
                dfs(i, j);
                res = max(res, cnt); //res存储至今最大区块
            }
        }
    }
    cout << res << endl;
    return 0;
}
