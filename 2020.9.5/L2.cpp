#include <bits/stdc++.h>
using namespace std;

int main()
{
    double dis[10], oil[10]; //dis表示距终点距离，oil表示第i个点储油量
    int i = 1, k = 1;
    dis[1] = 500.000;     //倒数第一个储油点距终点500km
    oil[1] = 500.000;     //倒数第一个储油点储油500L
    while (dis[i] < 1000) //倒推法求储油点
    {
        i++;
        k++;
        dis[i] = dis[i - 1] + 500.0 / (2 * k - 1); //卡车至少从i=k+1处开k趟满载车至i=k处,加上从i=k处返回i=k+1的k-1趟返程空间，合计2k-1次。这2k-1次总耗油量按最省要求为500公升
        oil[i] = 500 + oil[i - 1];                 //在i=k处贮藏k*500公升汽油
    }
    dis[i] = 1000;                         //i=n至始点的距离为1000-dis[n]
    oil[i] = oil[i] - (dis[i] - 1000) * k; //为了在i=n处取得n*500公升汽油，卡车至少从始点开n+1次满载车至i=n，加上从i=n返回始点的n趟返程空车，合计2n+1次，2n+1趟的总耗油量应正好为(1000-dis[n])*(2n+1)，即始点藏油为oil[n]+(1000-dis[n])*(2n+1)

    cout << "No."
         << "\t"
         << "Distance(k.m.)"
         << "\t"
         << " oil(litre)" << endl;
    for (int j = i; j > 0; j--)
    {
        cout << setprecision(5) << i - j << "\t" << setprecision(5) << 1000 - dis[j] << "\t\t" << oil[j] << endl;
    }

    return 0;
}