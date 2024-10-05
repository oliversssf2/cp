#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    int case_num = 1;
    while (cin >> m >> n, m != 0)
    {
        if (case_num > 1)
            cout << endl;

        int sol[m + 2][n + 2];

        for (int i = 0; i < (m + 2); i++)
        {
            for (int j = 0; j < (n + 2); j++)
            {
                sol[i][j] = 0;
            }
        }

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                char c;
                cin >> c;
                if (c == '*')
                    sol[i][j] = -1;
            }
        }

        for (int i = 1; i <= m; i++)
        { // iterate the entire map
            for (int j = 1; j <= n; j++)
            {
                if (sol[i][j] == -1)
                    continue; // skip if the square has a mine.
                for (int x = i - 1; x <= i + 1; x++)
                { // iterate over the 8 squares adjacent to each square to calculate the solution
                    for (int y = j - 1; y <= j + 1; y++)
                    {
                        if (x != i || y != j)
                        { // don't count the central square
                            if (sol[x][y] == -1)
                                sol[i][j]++;
                        }
                    }
                }
            }
        }

        cout << "Field #" << case_num << ":" << endl;
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (sol[i][j] == -1)
                    cout << '*';
                else
                    cout << sol[i][j];
            }
            cout << endl;
        }
        case_num++;
        // cout << endl;
    }
}