#include <bits/stdc++.h>
// #include <iostream>
// #include <vector>
using namespace std;

int main()
{
    unordered_map<int, int> v;
    int t, m, n, tmp, sum;
    cin >> t;
    while(t--){
        v = unordered_map<int, int>();
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> tmp;
            v[tmp]++;
        }
        for(int j = 0; j < m; j++){
            cin>>tmp;
            v[tmp]--;
        }
        sum = 0;
        // for(int i = 1; i < 101; i++){
        //     sum += abs(v[i]);
        // }
        for(auto it = v.begin(); it != v.end(); it++){
            sum += abs(it->second);
        }
        cout << sum << endl;
    }
}