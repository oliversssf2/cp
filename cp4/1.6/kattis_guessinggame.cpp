#include <bits/stdc++.h>
using namespace std;

int main()
{
    int high = 11, low = 0;
    int a;
    string s;
    bool res = true;
    while(true){
        cin >> a;
        if(a == 0) break;
        cin >> s;

        if(s == "too high"){
            high = a-1;
        }

        if (s == "too low"){
            low = a+1;
        }

        if (s == "right on"){
            if(a < low || a > high){
                res = false;
            }
            break;
        }

        if(high < low){
            res = false;
            break;
        }
    }

    if(res){
        cout << "Stan may be honest" << endl;
    } else {
        cout << "Stan is dishonest" << endl;
    }
}
