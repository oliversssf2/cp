#include <bits/stdc++.h>
using namespace std;

// SKIPPED cuz don't wanna enuermate //

/*
Input:
5
1234 2 2
111 1 0
567 0 1
91543 5 0
91543 0 5

Output:
6
192
234
1
44
*/

/*
For each positions in k, x, below are the possible cases:
1. x swap with a free_pos -> derangemnet(j-1, k-1)
2. x take another position, y, from k, but no swap -> derangement()


*/

constexpr int fact[6] = { 1, 1, 2, 6, 24, 120 };

int derangement(int j, int k) //derangemnt is a type of permutation after which certain elements cannot remain the in same position. see https://en.wikipedia.org/wiki/Derangement for more info
{ // j is the total # of position, k is the # of position that cant be fixed;
    if (k == 0)
        return fact[j]; // base case;    
    if (j == 1 && k == 1) return 0; // another base case;

    int result = 0;
    int free_pos = j - k;
    if (free_pos > 0)
    {
        result += (free_pos * derangement(j - 1, k - 1));
    }
    if (k >= 2) 
    {
        result += (k-1) * derangement(j-2, k-2);
        result += (k-1) * derangement(j-1, k-1);
    }

    return result;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string guess;
        int a, b;
        cin >> guess >> a >> b;
        int num_digit = guess.size();
        cout << fact[num_digit]/(fact[num_digit-a]*fact[a]) * derangement(num_digit-a, b) << endl;
    }
}