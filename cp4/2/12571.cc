#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, q;
        vector<int> vi;
        cin >> n >> q;

        int tmp;
        for(n--){
            cin >> tmp;
            vi.push_back(tmp);
        }

        for(q--){
            int max_v = 0;
            cin >> tmp;
            for(int i = 0; i < vi.size(); i++){
                max_v = max(max_v, tmp & vi[i]);
            }
            cout << max_v << endl;
        }
    }
}