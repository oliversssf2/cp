#include <bits/stdc++.h>
using namespace std;

int main()
{
    int w, h;
    while(cin >> h >> w){
        if (w == 0 && h == 0){
            return 0;
        }

        int res = 0;
        int cur = 0;
        int x;
        for(int i = 0; i < w; i++){
            cin >> x;
            if ((h-x) > cur){
                res += ((h-x) - cur);
            } 
            cur = (h-x);
        }
        cout << res << endl;
    }
    return 0;
}