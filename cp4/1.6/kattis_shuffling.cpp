#include <bits/stdc++.h>
using namespace std;

vector<int> shuffle(const vector<int> &deck, string mode)
{
    vector<int> new_deck;
    if (mode == "out")
    {
        for (size_t i = 0; i < deck.size() / 2; i++)
        {
            new_deck.push_back(deck[i]);
            new_deck.push_back(deck[(deck.size()+1)/2 + i]);
        }
        if (deck.size() % 2 == 1)
        {
            new_deck.push_back(deck[(deck.size()+1)/2 - 1]);
        }
    }
    else if (mode == "in")
    {

        for (size_t i = 0; i < deck.size() / 2; i++)
        {
            new_deck.push_back(deck[deck.size() / 2 + i]);
            new_deck.push_back(deck[i]);
        }
        if (deck.size() % 2 == 1)
        {
            new_deck.push_back(deck[deck.size() - 1]);
        }
    }
    return new_deck;
}

int main()
{
    int deck_size;
    string mode;
    cin >> deck_size >> mode;

    vector<int> deck(deck_size);
    for (int i = 0; i < deck_size; i++)
    {
        deck[i] = i;
    }

    vector<int> new_deck = shuffle(deck, mode);
    int turn = 1;
    while (new_deck != deck)
    {
        new_deck = shuffle(new_deck, mode);
        turn++;
    }
    cout << turn << endl;
}