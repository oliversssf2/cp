#include <bits/stdc++.h>
using namespace std;

/*
SampleInput
2 3
5 5
4 7
0 0
SampleOutput
4 knights may be placed on a 2 row 3 column board.
13 knights maybeplaced on a 5 row 5 column board.
14 knights maybeplaced on a 4 row 7 column board.
*/


int main()
{
    int m, n;
    while(cin >> m >> n, !(m == 0 && n == 0)){
        int a = min(m,n);
        int b = max(m, n);
        if (a == 1){
            cout << b << " knights may be placed on a " << m << " row " << n << " column board." << endl;
        } else if (a == 2) {
            int tmp = (b/4) * 4 + min((b%4),2)*2;
            cout << tmp << " knights may be placed on a " << m << " row " << n << " column board." << endl;
        } else {
            cout << ((a*b)+1)/2 << " knights may be placed on a " << m << " row " << n << " column board." << endl;
        }
    }
}