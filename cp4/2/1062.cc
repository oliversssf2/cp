#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int i = 1;
    while(cin >> s){
        if (s == "end") break;

        vector<stack<char>> vsc;
        for(char c : s){
            if(vsc.size() == 0) {
                stack<char> stk;
                stk.push(c);
                vsc.push_back(stk);
            } else {
                int added = 0;
                for(size_t i = 0; i < vsc.size(); i++){
                    if (c <= vsc[i].top()) {
                        vsc[i].push(c);
                        added = 1;
                        break;
                    }
                }
                if(added == 0){
                    stack<char> stk;
                    stk.push(c);
                    vsc.push_back(stk);
                }
            }
        }
        cout << "Case " << i << ": "<< vsc.size() << endl;
        i++;
    }
}