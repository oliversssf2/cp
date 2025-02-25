#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;

    while (cin >> s)
    {
        int state = 0; // 1 means home, 0 means end
        deque<char> line;
        string cur = "";
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '[' || s[i] == ']')
            {
                if (state == 1)
                {
                    for (int j = cur.size() - 1; j >= 0; j--)
                    {
                        line.push_front(cur[j]);
                    }
                }
                else
                {
                    for (size_t j = 0; j < cur.size(); j++)
                    {
                        line.push_back(cur[j]);
                    }
                }
                cur = "";
                state = s[i] == '[' ? 1 : 0;
            }
            else
            {
                cur += s[i];
            }
        }

        if (state == 1)
        {
            for (int j = cur.size() - 1; j >= 0; j--)
            {
                line.push_front(cur[j]);
            }
        }
        else
        {
            for (size_t j = 0; j < cur.size(); j++)
            {
                line.push_back(cur[j]);
            }
        }

        while (!line.empty())
        {
            cout << line.front();
            line.pop_front();
        }
        cout << endl;
    }
}