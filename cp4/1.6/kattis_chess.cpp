#include <bits/stdc++.h>
using namespace std;

/*
Sample Input:

3
E 2 E 3
F 1 E 8
A 3 A 3

Sample Output:

Impossible
2 F 1 B 5 E 8
0 A 3

*/

int main()
{
    unordered_map<char, int> col_chars = {
        {'A', 1},
        {'B', 2},
        {'C', 3},
        {'D', 4},
        {'E', 5},
        {'F', 6},
        {'G', 7},
        {'H', 8},
    };

    unordered_map<int, char> col_indices = {
        {1, 'A'},
        {2, 'B'},
        {3, 'C'},
        {4, 'D'},
        {5, 'E'},
        {6, 'F'},
        {7, 'G'},
        {8, 'H'}};

    int n;
    cin >> n;
    while (n--)
    {
        char col_a_char, col_b_char;
        int col_a, col_b;
        int row_a, row_b;
        cin >> col_a_char >> row_a >> col_b_char >> row_b;
        col_a = col_chars[col_a_char];
        col_b = col_chars[col_b_char];

        if ((col_a + row_a) % 2 != (col_b + row_b) % 2)
        {
            printf("Impossible\n");
        }

        else if (col_a == col_b && row_a == row_b)
        {
            printf("%d %c %d\n", 0, col_a_char, row_a);
        }

        else if (col_a + row_a == col_b + row_b || (row_a - col_a) == (row_b - col_b))
        {
            printf("%d %c %d %c %d\n", 1, col_a_char, row_a, col_b_char, row_b);
            // printf("%d %c %d\n", col_b_char, row_b);
        }

        else
        {
            int col_search, row_search; // col and row being searched
            int done = 0;

            // 1. search upward-diagonal
            col_search = col_a - (min(row_a, col_a) - 1); // find the col and row of the left-most square of the
            row_search = row_a - (min(row_a, col_a) - 1); // upward diagonal A is on.

            while (max(col_search, row_search) <= 8)
            {
                if (col_search + row_search == col_b + row_b)
                {
                    done = 1;
                    break;
                }
                col_search++;
                row_search++;
            }

            if (done == 0)
            {
                col_search = col_a - min(col_a - 1, 8 - row_a); // find the left-most square of the downward diagonal
                row_search = row_a + col_a - col_search;

                while (col_search <= 8 && row_search >= 1)
                {
                    if (row_search - col_search == row_b - col_b)
                        break;
                    col_search++;
                    row_search--;
                }
            }
            // 2. search downward-diagonal if the previous search fails

            printf("%d %c %d %c %d %c %d\n", 2, col_a_char, row_a, col_indices[col_search], row_search, col_b_char, row_b);
        }
    }
}