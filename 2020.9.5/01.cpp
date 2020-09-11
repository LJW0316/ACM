#include <bits/stdc++.h>
using namespace std;

int main()
{
    int pre = -1, res = 0;
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'Y')
        {
            if (i - pre > res)
            {
                res = i - pre;
            }
            pre = i;
        }
    }
    if (str.length() - pre > res)
        res = str.length() - pre;
    cout << res << endl;
    return 0;
}
