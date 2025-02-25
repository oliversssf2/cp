#include <bits/stdc++.h>
using namespace std;

unordered_map<char, int> dnamap{
    {'A',1},
    {'T',2},
    {'C',3},
    {'G',4}
};

int calc_inv(string vi){
    int inv = 0;
    for(size_t i = 0; i < vi.length(); i++){
        for(size_t j = 0; j < vi.length()-i; j++){
            // if (dnamap[vi[j]] > dnamap[vi[j+1]]){
            if (vi[j] > vi[j+1]){
                swap(vi[j], vi[j+1]);
                inv++;
            }
        }
    }
    return inv;
}

struct DNA {
    int inv;
    string seq;
};

int main()
{
    int t; cin >> t;
    while(t--){
        int n,m;
        vector<DNA> results;

        cin>>n>>m;
        while(m--){
            struct DNA dna; 
            cin >> dna.seq;
            dna.inv = calc_inv(dna.seq);
            results.push_back(dna);
        }

        stable_sort(results.begin(), results.end(), [](DNA a, DNA b){ return a.inv < b.inv; } );
        for(DNA& a : results){
            cout << a.seq << endl;
        }
        if(t != 0) cout << endl;

    }
}