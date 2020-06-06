
#include <iostream>
#include <cstdlib>
#include <map>
#include <string>
using namespace std;

int pro(int len)
{
    int sum = 1;
    for (int i = 1; i < len; i++)
    {
        sum *= 10;
    }
    return sum;
}

int main()
{
    string s;
    map<char, int> m;
    map<int, char> m1;

    m['I'] = 1;
    m['V'] = 5;
    m['X'] = 10;
    m['L'] = 50;
    m['C'] = 100;
    m['D'] = 500;
    m['M'] = 1000;
    m1[1] = 'I';
    m1[2] = 'V';
    m1[3] = 'X';
    m1[4] = 'L';
    m1[5] = 'C';
    m1[6] = 'D';
    m1[7] = 'M';
    while (cin >> s)
    {

        if (s[0] >= '0' && s[0] <= '9')
        {
            int len = s.length(), sum = 0, sum1 = 0;
            for (int i = 0; i < s.length(); i++)
            {
                sum1 = 0;
                sum = 0;
                sum = (s[i] - '0') * pro(len);
                if (sum == 0)
                    continue;

                if (sum / pro(len) <= 3) //處理重複測資
                {
                    sum1 = m[m1[len * 2 - 1]];
                    cout << m1[len * 2 - 1];
                    while (sum != sum1)
                    {
                        sum1 += m[m1[len * 2 - 1]];

                        cout << m1[len * 2 - 1];
                    }
                }
                else if (sum > (m[m1[len * 2]] + m[m1[len * 2 - 1]] * 3)) //處理IX_XC_CM
                {

                    sum1 = m[m1[len * 2 + 1]];
                    while (sum != sum1)
                    {
                        sum1 -= m[m1[len * 2 - 1]];
                        cout << m1[len * 2 - 1];
                    }
                    cout << m1[len * 2 + 1];
                }
                else
                {
                    if (sum > m[m1[len * 2]])
                    {
                        sum1 = m[m1[len * 2]];
                        cout << m1[len * 2];
                        while (sum1 != sum)
                        {
                            sum1 += m[m1[len * 2 - 1]];
                            cout << m1[len * 2 - 1];
                        }
                    }
                    else
                    {
                        sum1 = m[m1[len * 2]];
                        while (sum1 != sum)
                        {
                            sum1 -= m[m1[len * 2 - 1]];
                            cout << m1[len * 2 - 1];
                        }
                        cout << m1[len * 2];
                    }
                }
                len--;
            }
            cout << endl;
        }
        else
        {
            int sum = 0;
            for (int i = s.length() - 1; i >= 0; i--)
            {
                if (m[s[i]] < m[s[i + 1]])
                {
                    sum -= m[s[i]];
                }
                else
                {
                    sum += m[s[i]];
                }
            }
            cout << sum << endl;
        }
        s = "";
        s.clear();
    }
    return 0;
}
