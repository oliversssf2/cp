#include <bits/stdc++.h>
using namespace std;

/*
2
AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH
QH JH TH 9H 8H 7H 6H 5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S
AC KC QC JC TC 9C 8C 7C 6C 5C 4C 3C 2C AD KD QD JD TD 9D 8D 7D 6D 5D 4D 3D 2D AH KH
QH JH TH 9H 8H 7H 6H 5H 4H 3H 2H AS KS QS JS TS 9S 8S 7S 6S 5S 4S 3S 2S

1. read into two string vectors
2. operate on top 25 cards vector
3. concat remaining vectors
4. cout.

*/

unordered_map<char, int> card_value{
    {'1', 1},
    {'2', 2},
    {'3', 3},
    {'4', 4},
    {'5', 5},
    {'6', 6},
    {'7', 7},
    {'8', 8},
    {'9', 9},
    {'T', 10},
    {'J', 10},
    {'Q', 10},
    {'K', 10},
};


int main()
{
    int n;
    cin >> n;
    for (int j = 1; j <= n; j++)
    {
        vector<string> deck(52);
        for (int a = 0; a < 52; a++)
        {
            string tmp;
            cin >> tmp;
            deck[51 - a] = tmp;
        }

        int y = 0;
        for (int i = 0; i < 3; i++)
        {
            int x = card_value[deck[25][0]];
            y += x;
            if (x == 10)
            {
                deck.erase(deck.begin()+25);
            }
            else
            {
                deck.erase(deck.begin()+25 , deck.begin()+25 + (10 - x) + 1);
            }
        }

        // cout << y << endl;


        cout << "Case " << j << ": " << deck[deck.size() - y] << endl;
    }
}