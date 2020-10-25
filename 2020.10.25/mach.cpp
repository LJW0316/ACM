#include <iostream>
using namespace std;

int num[2001] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int main()
{
    int n, res = 0;
    cin >> n;
    for (int i = 10; i <= 2000; i++)
    {
        int j = i;
        while (j > 0)
        {
            num[i] += num[j % 10];
            j = j / 10;
        }
    }
    for (int i = 0; i <= 1000; i++)
    {
        for (int j = 0; j <= 1000; j++)
        {
            if (num[i] + num[j] + num[i + j] + 4 == n)
            {
                res++;
                cout << i << "+" << j << "=" << i + j << endl;
            }
        }
    }
    cout << res << endl;
    return 0;
}