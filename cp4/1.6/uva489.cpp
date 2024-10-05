#include <bits/stdc++.h>
using namespace std;

/*
Sample Input
1
cheese
chese
2
cheese
abcdefg
3
cheese
abcdefgij
-1

Sample Output
Round 1
You win.
Round 2
You chickened out.
Round 3
You lose.
*/

int num_char_in_string(string &s, char c)
{
    int num = 0;
    for (char tmp : s)
    {
        if (tmp == c)
            num++;
    }
    return num;
}

int main()
{
    int n;
    while (cin >> n, n != -1)
    {
        string solution;
        string input;

        int result = 0; // 0 for unfinished, 1 for winning, 2 for losing

        cin >> solution;
        cin >> input;

        int num_solved_chars = 0;
        int num_strokes = 0;

        unordered_set<char> guessed_char;

        for (char c : input)
        {
            if (guessed_char.find(c) == guessed_char.end()) // if the letter hasn't been gussed before, process it; else ignore it
            {
                int num_occurence = num_char_in_string(solution, c);
                if (num_occurence == 0) // character not found in solution
                {
                    num_strokes++;
                    if (num_strokes == 7)
                    {
                        result = 2; // indicate losing
                        break;
                    }
                }
                else
                {
                    num_solved_chars += num_occurence;
                    if (num_solved_chars == solution.size())
                    {
                        result = 1; // indicate winning
                        break;
                    }
                }
                guessed_char.insert(c);
            }
        }

        cout << "Round " << n << endl;
        if (result == 0)
        {
            cout << "You chickened out." << endl;
        }
        else if (result == 1)
        {
            cout << "You win." << endl;
        }
        else if (result == 2)
        {
            cout << "You lose." << endl;
        }
    }
}