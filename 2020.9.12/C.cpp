#include <iostream>
using namespace std;

int main()
{
    int n, x = 0;
    int a[1005];
    cin >> n;
    if (n == 0)
        cout << 0 << endl;
    else
    {
        while (n != 0)
        {
            if (n < 0 && n % -2 != 0) //被除数是负数且不能被2整除的情况
            {
                a[x++] = abs(n % -2);
                n = n / -2 + 1; //商比正常进制转换+1
            }
            else
            {
                a[x++] = abs(n % -2); //正常进制转换
                n = n / -2;
            }
        }
        for (int i = x - 1; i >= 0; i--)
        {
            cout << a[i];
        }
    }
    return 0;
}