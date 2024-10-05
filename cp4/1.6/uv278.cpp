#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--){
        char p;
        int m, n;
        cin >> p >> m >> n;
        if (p == 'r') cout << min(m, n) << endl;
        else if (p == 'k') cout << (m*n+1)/2 << endl;
        else if (p == 'Q') cout << min(m, n) << endl;
        else if (p == 'K') cout << ((m+1)/2)*((n+1)/2) << endl;
    }
}