#include <bits/stdc++.h>
using namespace std;

/*
SampleInput
28 51 29 50 52
50 26 19 10 27
10 20 30 24 26
46 48 49 47 50
0 0 0 0 0
SampleOutput
30
-1
21
51
*/

/*
Logic:
1. de > abc -> smallest card in the deck would do
2. de < two of abc -> no solution be definition (de < abc is a subset of this scenario)
3.

there can only be on card
*/

int main()
{
    int a, b, c, d, e;
    while (cin >> a >> b >> c >> d >> e, (a + b + c + d + e) != 0)
    {
        vector<int> x{a, b, c};
        vector<int> y{d, e};
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        bitset<53> avail;
        avail.set(); // set all bits to 1

        avail[a].flip();
        avail[b].flip();
        avail[c].flip();
        avail[d].flip();
        avail[e].flip();

        int card = -1;

        if (y[0] > x[2])
        {
            for (int i = 1; i <= 52; i++)
            {
                if (avail[i])
                {
                    card = i;
                    break;
                }
            }
        }
        else if (y[1] > x[2])
        {
            if (y[0] > x[1])
            {
                for (int i = x[1] + 1; i <= 52; i++)
                {
                    if (avail[i])
                    {
                        card = i;
                        break;
                    }
                }
            }
            else
            {
                for (int i = x[2] + 1; i <= 52; i++)
                {
                    if (avail[i])
                    {
                        card = i;
                        break;
                    }
                }
            }
        }
        else if (y[0] > x[1])
        {
            for (int i = x[1] + 1; i <= 52; i++)
            {
                if (avail[i])
                {
                    card = i;
                    break;
                }
            }
        }

        cout << card << endl;
    }
}