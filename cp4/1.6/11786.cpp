#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    char tmp;
    scanf("%c", &tmp);

    while (n--)
    {
        char ch;
        int res = 0;
        stack<int> stk;
        for (int i = 0; scanf("%c", &ch) != EOF; i++)
        {
            if(ch == '\n') break;
            if(ch == '\\'){
                stk.push(i);
            } else if (ch == '/'){
                if(!stk.empty()){
                    int j = stk.top();
                    stk.pop();
                    res += (i-j);
                }
            }
        }
        cout << res << endl;
    }
}