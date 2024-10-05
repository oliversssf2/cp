#include <bits/stdc++.h>
using namespace std;

/*
SampleInput
1 1
1000
1000
3 4
1 3 5
2 4 6 8
10 9
1 1 2 3 5 7 8 8 9 15
2 2 2 3 4 6 10 11 11
0 0
SampleOutput
0
3
4
*/


int main()
{
    int m, n;
    while(cin >> m >> n, m != 0 && n != 0){
        vector<int> cards(100001, 0);
        while(m--){
            int tmp;
            cin >> tmp;
            if (cards[tmp] == 0) cards[tmp] += 1; // 1 if only a has it
        }
        while(n--){
            int tmp;
            cin >> tmp;
            if (cards[tmp] == 1) cards[tmp] = 3; // 3 if both have it
            else if (cards[tmp] == 0) cards[tmp] = 2; // 2 if only b has it
        }
        auto only_a = count(cards.begin(), cards.end(), 1);
        auto only_b = count(cards.begin(), cards.end(), 2);
        cout << min(only_a, only_b) << endl;
    }
}