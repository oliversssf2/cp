#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_map<char, int> dominant = {
        {'A', 11},
        {'K', 4},
        {'Q', 3},
        {'J', 20},
        {'T', 10},
        {'9', 14},
        {'8', 0},
        {'7', 0},
    };
    
    unordered_map<char, int> not_dominant = {
        {'A', 11},
        {'K', 4},
        {'Q', 3},
        {'J', 2},
        {'T', 10},
        {'9', 0},
        {'8', 0},
        {'7', 0},
    };

    int n;
    char dom_suit;
    int value = 0;
    cin >> n >> dom_suit;
    for(int i = 0; i < 4 * n; i++) 
    {
        char rank, suit;
        cin >> rank >> suit;

        if (suit == dom_suit){
            value += dominant[rank];
        } else {
            value += not_dominant[rank];
        }
    }
    cout << value << endl;
}