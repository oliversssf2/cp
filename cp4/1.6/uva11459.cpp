#include <bits/stdc++.h>
using namespace std;

constexpr auto max_size = std::numeric_limits<std::streamsize>::max();

/*
SampleInput
1
3 1 3
4 20
3
4
5


Position of player 1 is 20.
*/

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        if (a == 0)
        {
            for (int i = 0; i <= (b + c); i++)
                cin.ignore(max_size, '\n');
            continue;
        }

        vector<int> players(a);
        for (int i = 0; i < a; i++)
            players[i] = 1;

        vector<int> game(101);
        for (int i = 1; i <= 100; i++)
            game[i] = i;

        while (b--)
        {
            int in, out;
            cin >> in >> out;
            game[in] = out;
        }

        for (int i = 0; i < c; i++)
        {
            int die;
            cin >> die;
            if (players[i % a] + die >= 100)
            {
                players[i % a] = 100;
                for (int j = 0; j < (c - 1) - i; j++)
                { // if i = 4 and c = 8, there are (8-1)-4 = 3 die rolls that should be ignore;
                    cin >> die;
                }
                break; // end game if any player reaches 100
            }
            else
            {
                players[i % a] = game[players[i % a] + die];
                if (players[i % a] == 100)
                {
                    for (int j = 0; j < (c - 1) - i; j++)
                    { // if i = 4 and c = 8, there are (8-1)-4 = 3 die rolls that should be ignore;
                        cin >> die;
                    }
                    break; // end game if any player reaches 100
                }
            }
        }

        for (int i = 0; i < a; i++)
        {
            cout << "Position of player " << i + 1 << " is " << players[i] << "." << endl;
        }
    }
    return 0;
}