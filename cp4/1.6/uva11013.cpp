#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> ranks = {
    {'A', 0},
    {'2', 1},
    {'3', 2},
    {'4', 3},
    {'5', 4},
    {'6', 5},
    {'7', 6},
    {'8', 7},
    {'9', 8},
    {'T', 9},
    {'J', 10},
    {'Q', 11},
    {'K', 12}};

double get_payoff(const vector<string> &cards)
{
    vector<int> card_values(13);
    for (auto &card : cards)
    {
        auto value = ranks[card[0]];
        card_values[value]++;
    }

    // search for run of 5
    for (int i = 0; i < 13; i++)
    {
        int yes = 1;
        for (int j = 0; j < 5; j++)
        {
            yes &= (card_values[(i + j) % 13] > 0); // &= is a bitwise operator
        }
        if (yes)
            return 100.0f;
    }
    // search for run of 4
    for (int i = 0; i < 13; i++)
    {
        int yes = 1;
        for (int j = 0; j < 4; j++)
        {
            yes &= (card_values[(i + j) % 13] > 0);
        }
        if (yes)
            return 10.0f;
    }
    // search for run of 3 + run of 2
    for (int i = 0; i < 13; i++)
    {
        auto card_values_copy = card_values; // deep copy vector
        int yes_run_of_3 = 1;

        for (int j = 0; j < 3; j++)
        {
            yes_run_of_3 &= (card_values_copy[(i + j) % 13] > 0);
        }

        if (yes_run_of_3)
        {
            for (int j = 0; j != 3; j++)
                card_values_copy[(i + j) % 13]--; // -- to signify that the cards are already used in the run-of-3

            for (int j = 0; j != 13; j++)
            {
                // i+4 to skip the first 3 cards and skip a card to make sure run-of-4's are not captured
                if ((card_values_copy[j % 13] > 0) & (card_values_copy[(j + 1) % 13] > 0))
                {
                    return 5.0f;
                }
            }
        }
    }

    // search for run of 3
    for (int i = 0; i < 13; i++)
    {
        int yes = 1;
        for (int j = 0; j < 3; j++)
        {
            yes &= (card_values[(i + j) % 13] > 0);
        }
        if (yes)
            return 3.0f;
    }

    // search for run of 2 + run of 2
    for (int i = 0; i < 13; i++)
    {
        auto card_values_copy = card_values; // deep copy vector

        int yes_run_of_2 = (card_values_copy[i % 13] > 0) & (card_values_copy[(i + 1) % 13] > 0);

        if (yes_run_of_2)
        {
            for (int j = 0; j < 2; j++)
                card_values_copy[(i + j) % 13]--; // -- to signify that the cards are already used in the first run-of-2

            for (int j = 0; j != 13; j++)
            {
                // i+4 to skip the first 3 cards and skip a card to make sure run-of-4's are not captured
                if ((card_values_copy[j % 13] > 0) & (card_values_copy[(j + 1) % 13] > 0))
                {
                    return 1.0f;
                }
            }
        }
    }
    return 0.f;
}

void print_cards(vector<string> &cards)
{
    for (auto &card : cards)
    {
        cout << card << "  ";
    }
    cout << endl;
}

vector<string> full_deck{
    "AS",
    "2S",
    "3S",
    "4S",
    "5S",
    "6S",
    "7S",
    "8S",
    "9S",
    "TS",
    "JS",
    "QS",
    "KS",
    "AC",
    "2C",
    "3C",
    "4C",
    "5C",
    "6C",
    "7C",
    "8C",
    "9C",
    "TC",
    "JC",
    "QC",
    "KC",
    "AD",
    "2D",
    "3D",
    "4D",
    "5D",
    "6D",
    "7D",
    "8D",
    "9D",
    "TD",
    "JD",
    "QD",
    "KD",
    "AH",
    "2H",
    "3H",
    "4H",
    "5H",
    "6H",
    "7H",
    "8H",
    "9H",
    "TH",
    "JH",
    "QH",
    "KH",
};


int main()
{
    reverse(full_deck.begin(), full_deck.end());  // UVaJudge gives WA without reverse for some reason
    // for each line of input:
    // 1. read cards
    vector<string> cards(5);
    while (cin >> cards[0] >> cards[1] >> cards[2] >> cards[3] >> cards[4], cards[0] != "#")
    {
        // print_cards(cards);
        double payoff = get_payoff(cards);

        // 2. find max run for the cards
        // a. first remove the 5 cards from the deck
        auto deck = full_deck;
        for (auto &card : cards)
        {
            deck.erase(find(deck.begin(), deck.end(), card));
        }
        // b. for each of the five cards, calculate the average payoff if it was replaced by a
        //    random card in the deck
        vector<double> alt_payoffs(5);
        for (int i = 0; auto &card : cards)
        {
            auto new_cards = cards;
            new_cards.erase(find(new_cards.begin(), new_cards.end(), card));
            for (auto &rnd_card : deck)
            {
                new_cards.push_back(rnd_card);
                alt_payoffs[i] += (get_payoff(new_cards) - 1.0); // -1 is the exchange fee
                new_cards.pop_back();
            }
            i++;
        }

        // 3. for each of the five cards, swap with all remaining cards in the deck and calculate expectation
        string exchange_card;
        double max_payoff = payoff * 47.0;
        for (int i = 0; auto &p : alt_payoffs)
        {
            // cout << "Swapping " << cards[i] << " gives an average payoff of " << p << " while the original payoff is " << payoff << endl;
            if (p > max_payoff)
            {
                exchange_card = cards[i];
                max_payoff = p;
            }
            i++;
        }
        if (!exchange_card.empty())
            cout << "Exchange " << exchange_card << endl;
        else
            cout << "Stay" << endl;
    }
}