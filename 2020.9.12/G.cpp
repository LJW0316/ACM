#include <iostream>
using namespace std;

int method_0(int x, int y, int z) //情况1：无rgb花束
{
    int sum = 0;
    sum += x / 3;
    x = x % 3;
    sum += y / 3;
    y = y % 3;
    sum += z / 3;
    z = z % 3;
    return sum;
}

int method_1(int x, int y, int z) //情况2：一束rgb花束
{
    int sum = 0;
    if (x > 0 && y > 0 && z > 0)
    {
        x--;
        y--;
        z--;
        sum++;
    }
    sum += x / 3;
    x = x % 3;
    sum += y / 3;
    y = y % 3;
    sum += z / 3;
    z = z % 3;
    return sum;
}

int method_2(int x, int y, int z) //情况3：两束rgb花束
{
    int sum = 0;
    if (x > 1 && y > 1 && z > 1)
    {
        x -= 2;
        y -= 2;
        z -= 2;
        sum += 2;
    }
    sum += x / 3;
    x = x % 3;
    sum += y / 3;
    y = y % 3;
    sum += z / 3;
    z = z % 3;
    return sum;
}

int main()
{
    int r, g, b, s1, s2, s3;
    cin >> r >> g >> b;
    s1 = method_0(r, g, b);
    s2 = method_1(r, g, b);
    s3 = method_2(r, g, b);               //三束rgb可以拆分成rrr,ggg,bbb，故最优解对应的rgb其实只有0,1,2三种情况
    cout << max(max(s1, s2), s3) << endl; //输出三种情况中最大值
    return 0;
}