#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    while(getline(cin, str)){
        if (str == "Game Over") break;

        istringstream iss(str);

        int last_val = -1;
        int cur_val = -1;

        bool last_spare = false;
        bool last_strike = false;
        bool last_last_strike = false;

        int res = 0;
        
        char ch;
        while(iss >> ch){
            if(ch == '/'){
                cur_val = 10-last_val;
            } else if(ch == 'X'){
                cur_val = 10;
            } else {
                cur_val = ch - '0';
            }

            if(last_spare || last_strike){
                res += cur_val;
            } 
            
            if(last_last_strike){
                res += cur_val;
            }

            res += cur_val;
            

            // if(last_spare){
            last_spare = false;
            // }

            // if(last_last_strike){
            last_last_strike = false;
            // }

            if(last_strike){
                last_strike = false;
                last_last_strike = true;
            }


            if(ch == '/'){
                last_spare = true;
            }

            if(ch == 'X'){
                last_strike = true;
            }
            last_val = cur_val;
        }

        cout << res << endl;
    }
}