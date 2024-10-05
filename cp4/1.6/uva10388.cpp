#include <bits/stdc++.h>
using namespace std;

/*
Sample Input
1
ABCDA
CBADC
 
Sample Output
Snap! for Jane: BCBA
Snap! for Jane: DADCBCBA
Snap! for John: CBAC
Snap! for John: ADADCBAC
John wins.

*/

int main()
{
    int n;
    cin >> n;
    while(n--){
        string s1, s2;
        cin >> s1 >> s2;

        string fu1, fu2;
        for(int i = 0; i < 1000; i++){
            if (i == 1000) break; // end game after 1000 turns
            fu1.insert(0, 1, s1[0]);
            fu2.insert(0, 1, s2[0]);
            s1.erase(s1.begin());
            s2.erase(s2.begin());
            if(fu1[0] == fu2[0]){
                int ind = random()/141%2;
                if (ind == 0){
                    fu1 = fu2 + fu1;
                    fu2.clear();
                    cout << "Snap! for Jane: " << fu1 << endl;
                } else {
                    fu2 = fu1 + fu2;
                    fu1.clear();
                    cout << "Snap! for John: " << fu2 << endl;
                }
            }

            if (s1.size() == 0 || s2.size() == 0) {
                if (s1.size() == 0 && fu1.size() == 0) break;
                else if (s2.size() == 0 && fu2.size() == 0) break;
                else {
                    if (s1.size() == 0){
                        reverse_copy(fu1.begin(), fu1.end(), back_inserter(s1));
                        fu1.clear();
                    }
                    if (s2.size() == 0){
                        reverse_copy(fu2.begin(), fu2.end(), back_inserter(s2));
                        fu2.clear();
                    }
                }

            }
        }
        if(fu1.size() == 0) cout << "John wins." << endl;
        else if(fu2.size() == 0) cout << "Jane wins." << endl;
        else cout << "Keeps going and going ..." << endl;
        if (n) cout << endl; // sometimes printing an empty line at the end causes PresentationE.
    }

}