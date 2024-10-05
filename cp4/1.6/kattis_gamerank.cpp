#include <bits/stdc++.h>
using namespace std;

/*
0-10 stars: rank 25 - 21
11-25 stars: rank 20 - 16
26-45 stars: rank 15 - 11
46-95 stars: rank 10 - 1
96+ stars: rank legend
*/

int main()
{
    unordered_map<int, int> rankup_stars;
    for(int i = 21; i <= 25; i++) rankup_stars[i] = 2;
    for(int i = 16; i <= 20; i++) rankup_stars[i] = 3;
    for(int i = 11; i <= 15; i++) rankup_stars[i] = 4;
    for(int i = 1; i <= 10; i++) rankup_stars[i] = 5;

    string input;
    cin >> input;
    
    int winstreak = 0;
    int rank = 25;
    int stars = 0;

    for (auto c:input){
        if (c == 'W'){
            winstreak++;
            if (rank >= 6 && winstreak >= 3) {
                stars += 2;
            } else {
                stars += 1;
            }
            if (stars > rankup_stars[rank]){
                stars -= rankup_stars[rank];
                rank--;
            }
            if (rank == 0) break;
        } else {
            winstreak = 0;
            if (rank < 20) {
                stars--;
                if (stars == -1){
                    rank++;
                    stars = rankup_stars[rank]-1;
                }
            } 
            else if (rank == 20){
                if (stars != 0) stars--;
            }
        }
        // cout << c << " : " << rank << " : " << stars << endl;

    }

    if (rank == 0) cout << "Legend" << endl;
    else cout << rank << endl;
}