#include <bits/stdc++.h>
using namespace std;

/*
8
5
1 3 earth sun
2 6 mars sun
6 3 sun sun
7 5 earth moon
2 7 mars earth
*/

int main()
{
    int n, t;
    cin >> n >> t;

    // unordered_multimap<string, int> matchings;

    vector<string> cards(n + 1);

    unordered_set<string> faceup;

    while (t--)
    {
        int p1, p2;
        string c1, c2;
        cin >> p1 >> p2 >> c1 >> c2;
        cards[p1] = c1;
        cards[p2] = c2;
        if (c1 == c2)
        {
            faceup.insert(c1);
        }
    }

    // 1. find # of known cards and all pairs in known cards
    // 2. subtract face up from it
    // 3. count number of unknown card
    // 4. if # of unknown = 2 -> known +1
    // 5. if # of unknown = # of known -> += # of known
    // 6. if # of unknown > # of known -> no change.

    int num_known = 0;
    for (auto iter = cards.begin() + 1; iter != cards.end(); iter++)
    {
        if (!(*iter).empty())
            num_known++;
    }
    int num_faceup = faceup.size();
    int num_facedown_known = num_known - num_faceup * 2;

    // find # of pairs in facedown cards
    unordered_set<string> facedown_known;
    int num_facedown_pairs = 0;
    for (auto iter = cards.begin() + 1; iter != cards.end(); iter++)
    {
        if (!(*iter).empty())
        {
            if (faceup.find(*iter) == faceup.end()) // not faceup
            {
                if (facedown_known.find(*iter) != facedown_known.end()) // found more than once
                {
                    num_facedown_pairs++;
                }
                else
                {
                    facedown_known.insert(*iter);
                }
            }
        }
    }

    int num_facedown_known_unique = num_facedown_known - (2 * num_facedown_pairs);
    int num_unknown = n - num_known;

    int score = 0;
    score += num_facedown_pairs;

    if (num_facedown_known_unique == 0)
    {
        if (num_unknown == 2)
            score += 1;
    }
    else if (num_facedown_known_unique == num_unknown)
    {
        score += num_unknown;
    }

    cout << score << endl;
}