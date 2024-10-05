#include <bits/stdc++.h>
using namespace std;

// this code is trash don't read it
// use global variable since I fucked up the code ordering
map<char, tuple<int, int>> sym_pos; // symbol, tuple<y, x>
char image[100][100];
string input;
int x = 0, y = 0;

void run()
{
    // output image

    // 1. sort sym_pos;
    // no need since map are already sorted according to its key

    // 2. get lenght and width of the image
    // no need since `x` and `y` are the width and length

    // 3. populate image wtih '.'
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
            image[i][j] = '.';
    }

    int last_sym_y = -1, last_sym_x = -1;
    int sym_y = -1, sym_x = -1;

    // 4. process empty image according to sym_pos
    for (auto iter = sym_pos.begin(); iter != sym_pos.end(); iter++)
    {
        int sym = iter->first;
        sym_y = get<0>(iter->second);
        sym_x = get<1>(iter->second);

        if(islower(sym)) sym = toupper(sym);
        else if(isupper(sym)) sym = tolower(sym);
        image[sym_y][sym_x] = sym;

        if (sym_x == last_sym_x)
        {
            // connect the column
            int begin = min(sym_y, last_sym_y);
            int end = max(sym_y, last_sym_y);

            for (int i = begin; i != end; i++)
            {
                char tmp = image[i][sym_x];
                if (tmp == '.')
                    image[i][sym_x] = '|';
                else if (tmp == '-')
                    image[i][sym_x] = '+';
            }
        }
        else if (sym_y == last_sym_y)
        {
            // connect the row
            int begin = min(sym_x, last_sym_x);
            int end = max(sym_x, last_sym_x);

            for (int j = begin; j != end; j++)
            {
                char tmp = image[sym_y][j];
                if (tmp == '.')
                    image[sym_y][j] = '-';
                else if (tmp == '|')
                    image[sym_y][j] = '+';
            }
        }

        last_sym_x = sym_x;
        last_sym_y = sym_y;
    }
    for (int i = 0; i < y; i++)
    {
        for (int j = 0; j < x; j++)
        {
            cout << image[i][j];
        }
        cout << endl;
    }

    // reset for next image
    x = 0;
    y = 0;
    sym_pos.clear();
    cout << endl; // empty line to separate different cases
};

int main()
{
    while (getline(cin, input))
    {
        if (input.empty())
        {
            run();
            continue;
        }

        else
        {
            x = 0;
            for (char c : input)
            {
                if (c != '.')
                {
                    char tmp = c;
                    if (isupper(c)) tmp = tolower(c);   // flip upper and lower characters becuase upper comes before lower on the ascii table
                    else if(islower(c)) tmp = toupper(c);
                    sym_pos.insert({tmp, {y, x}});
                }
                x++;
            }
            y++;
        }
    }
    run();
}