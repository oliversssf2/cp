#include <bits/stdc++.h>
using namespace std;

// 1. P1 shoots first
// 2. if a player hits, they gain one more shot
// 3. every players get the same number of turn
// 4. game ends when one side loses all their ships (however, due to `3.`, a player might get another turn even if all their ships have sunk)
// 5. draw if both players lose all their ships
// 6. also draw if both have ships left.

int main()
{
    int t; 
    cin >> t;
    while(t--){
        int w, h, n;
        vector<string> map_1;
        vector<string> map_2;
        for(int i = 0; i < h; i++){
            string tmp;
            cin >> tmp;
            map_1.push_back(tmp);
        }
        for(int i = 0; i < h; i++){
            string tmp;
            cin >> tmp;
            map_2.push_back(tmp);
        }

        int num_ship_1 = 0;
        int num_ship_2 = 0;

        for (auto& m: {map_1, map_2}){
            for(auto& s: m){
                for(auto& c: s){
                    if (c == '#') num_ship_1++;
                }
            }
        }
        
        int current_player = 1;
        vector<string> &current_map = map_2;
        for(int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y; 
            y = h - y - 1;
            if (current_map[y][x] == '#'){
                current_map[y][x] == '_';
            }
        }
    }
}