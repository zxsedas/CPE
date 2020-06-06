#include <iostream>
#include <cstdlib>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    string s, temp;
    map<string, int> m;
    map<string, int>::iterator it;
    while (cin >> n && n != 0)
    {
        m.clear();
        for (int i = 0; i < n; i++)
        {
            s = "";
            s.clear();
            for (int j = 0; j < 5; j++)
            {
                temp = "";
                temp.clear();
                cin >> temp;
                s += temp;
            }
            sort(s.begin(), s.end());
            m[s] += 1;
        } //處理測資排序
        it = m.begin();
        int max = (*it).second;
        for (it = m.begin(); it != m.end(); it++)
        {

            if ((*it).second > max)
            {
                max = (*it).second;
            }
        }
        int sum = 0, flag = 0;
        for (it = m.begin(); it != m.end(); it++)
        {
            if (max == (*it).second)
            {
                sum += max;
                flag = 1;
            }
        }

        if (flag == 1)
        {
            cout << sum << endl;
        }
        else
        {

            cout << max << endl;
        }
    }

    return 0;
}