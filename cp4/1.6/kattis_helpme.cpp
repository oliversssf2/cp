#include <bits/stdc++.h>
using namespace std;

/*
+---+---+---+---+---+---+---+---+
|.r.|:n:|.b.|:q:|.k.|:::|.n.|:r:|
+---+---+---+---+---+---+---+---+
|:p:|.p.|:p:|.p.|:p:|.p.|:::|.p.|
+---+---+---+---+---+---+---+---+
|...|:::|.n.|:::|...|:::|...|:p:|
+---+---+---+---+---+---+---+---+
|:::|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|...|:::|...|:::|.P.|:::|...|:::|
+---+---+---+---+---+---+---+---+
|:P:|...|:::|...|:::|...|:::|...|
+---+---+---+---+---+---+---+---+
|.P.|:::|.P.|:P:|...|:P:|.P.|:P:|
+---+---+---+---+---+---+---+---+
|:R:|.N.|:B:|.Q.|:K:|.B.|:N:|.R.|
+---+---+---+---+---+---+---+---+
*/

/*
White: Ke1,Qd1,Ra1,Rh1,Bc1,Bf1,Nb1,a2,c2,d2,f2,g2,h2,a3,e4
Black: Ke8,Qd8,Ra8,Rh8,Bc8,Ng8,Nc6,a7,b7,c7,d7,e7,f7,h7,h6
*/

constexpr auto max_size = numeric_limits<std::streamsize>::max();

unordered_map<int, char> col_indices = {
    {1, 'a'},
    {2, 'b'},
    {3, 'c'},
    {4, 'd'},
    {5, 'e'},
    {6, 'f'},
    {7, 'g'},
    {8, 'h'}};

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

struct
{
    bool operator()(string a, string b) const
    {
        int col_a = a[0] - 48;
        char row_a = a[1];
        int col_b = b[0] - 48;
        char row_b = b[1];

        if (row_a < row_b)
        {
            return true;
        }
        else if (row_b < row_a)
        {
            return false;
        }
        else
        {
            return col_a < col_b;
        }
    }

} whiteLess;

struct
{
    bool operator()(string a, string b) const
    {
        int col_a = a[0] - 48;
        char row_a = a[1];
        int col_b = b[0] - 48;
        char row_b = b[1];

        if (row_a < row_b)
        {
            return false;
        }
        else if (row_b < row_a)
        {
            return true;
        }
        else
        {
            return col_a < col_b;
        }
    }

} blackLess;

int main()
{
    map<char, vector<string>> board = {
        {'k', vector<string>()},
        {'q', vector<string>()},
        {'r', vector<string>()},
        {'b', vector<string>()},
        {'n', vector<string>()},
        {'p', vector<string>()},
        {'K', vector<string>()},
        {'Q', vector<string>()},
        {'R', vector<string>()},
        {'B', vector<string>()},
        {'N', vector<string>()},
        {'P', vector<string>()},
    };

    int col = 1;
    int row = 8;
    while (row)
    {
        string s;
        cin.ignore(max_size, '\n');
        getline(cin, s);
        for (col = 1; col <= 8; col++)
        {
            char piece = s[2 + (col - 1) * 4];
            if (piece != '.' && piece != ':')
            {
                string pos = col_indices[col] + to_string(row);
                board[piece].push_back(pos);
            }
        }
        row--;
    }

    // print out the positions in the correct format
    string whiteOutput = "White: ";
    for (char s : {'K', 'Q', 'R', 'B', 'N', 'P'})
    {
        sort(board[s].begin(), board[s].end(), whiteLess);
        // string whiteOutput;
        for (string u : board[s])
        {
            if (s != 'P')
            {
                whiteOutput.push_back((char)toupper(s));
            }
            whiteOutput.append(u);
            whiteOutput.push_back(',');
        }
    }
    whiteOutput.pop_back();
    cout << whiteOutput << endl;

    string blackOutput = "Black: ";
    for (char s : {'k', 'q', 'r', 'b', 'n', 'p'})
    {
        sort(board[s].begin(), board[s].end(), blackLess);
        // string blackOutput;
        for (string u : board[s])
        {
            if (s != 'p')
            {
                blackOutput.push_back((char)toupper(s));
            }
            blackOutput.append(u);
            blackOutput.push_back(',');
        }
    }
    blackOutput.pop_back();
    cout << blackOutput << endl;
}