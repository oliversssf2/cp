#include <bits/stdc++.h>
using namespace std;

/*
SampleInput

17 17 49
17 49 56
17 49 9
17 49 17
17 49 25
17 49 33
17 49 41
17 49 49
56 48 49

SampleOutput

Illegal state
Illegal move
Illegal move
Illegal move
Move not allowed
Continue
Continue
Illegal move
Stop
*/

int main()
{
    int q, k, m;
    while (cin >> k >> q >> m)
    {
        // cout << k << " " << q << " " << m << endl;
        if (q == k)
        {
            cout << "Illegal state" << endl;
            continue;
        }
        else
        {
            int qx = q % 8;
            int qy = q / 8;
            int kx = k % 8;
            int ky = k / 8;
            int mx = m % 8;
            int my = m / 8;

            // check if move is allowed
            if (m == k || (mx != qx && my != qy) || m == q) // move to same square or move to squares on other hori/vert.
            {
                cout << "Illegal move" << endl;
                continue;
            }

            if (qx == kx && qx == mx) // same x and move along the same x
            {
                if ((qy < ky && ky < my) || (my < ky && ky < qy))
                {
                    cout << "Illegal move" << endl;
                    continue;
                }
            }

            if (qy == ky && qy == my) // same y and move along the same y
            {
                if ((qx < kx && kx < mx) || (mx < kx && kx < qx))
                {
                    cout << "Illegal move" << endl;
                    continue;
                }
            }

            int diff = abs(k-m);
            if ((diff == 1 && (k / 8 == m / 8)) || diff == 8)
            {
                cout << "Move not allowed" << endl;
                continue;
            }


            if ((m == 9 && k == 0) || (m == 14 && k == 7) || (m == 49 && k == 56) || (m == 54 && k == 63))
            {
                cout << "Stop" << endl;
                continue;
            }
            else
            {
                cout << "Continue" << endl;
                continue;
            }
        }
    }
}