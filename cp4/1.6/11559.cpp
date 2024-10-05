#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, B, H, W;
    while (cin >> N >> B >> H >> W)
    {
        bool ok = false;

        int res = INT_MAX;
        for (int i = 0; i < H; i++)
        {
            int p;
            int a;
            cin >> p;
            for (int j = 0; j < W; j++)
            {
                cin >> a;
                if (a >= N && p * N <= B)
                {
                    ok = true;
                    res = min(res, N * p);
                }
            }
        }
        if (ok)
        {
            cout << res << endl;
        }
        else
        {
            cout << "stay home" << endl;
        }
    }
}