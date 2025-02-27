#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<string> ss;
    string s;

    while(cin >> s){
        if (!s.empty()){
            string word;
            for(char& c : s){
                if (isalpha(c)){
                    word += tolower(c);
                }
            }
            ss.insert(word);
        }
    }
    for (auto it = ss.begin(); it != ss.end(); it++){
        cout << *it << endl;
    }
}