#include <bits/stdc++.h>
using namespace std;


int main() {
    unordered_map<string, int> m;
    string word;
    queue<string> sq;

    for(char c = 'a'; c <= 'z'; c++){
        sq.push(string(1, c));
    }
    
    int i = 1;
    
    while(!sq.empty()){
        word = sq.front();
        sq.pop();
        m[word] = i++;
        if (word.size() == 5) continue;

        for(char i = word[word.size()-1] + 1; i <= 'z'; i++){
            sq.push(word + i);
        }
    }

    string input;
    while(cin>>input){
        cout << m[input] << endl;
    }


    return 0;
}