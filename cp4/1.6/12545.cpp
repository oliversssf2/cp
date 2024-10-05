#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin>>n;
    for(int k = 1; k <= n; k++){
        string s;
        string t;
        cin >> s >> t;

        int num_zero_one = 0;
        int num_one_zero = 0;
        int num_q = 0;  // number of question marks that can be converted into a 0;
        int res = 0;

        int sz = s.length();
        for(int i = 0; i < sz; i++){
            if(s[i] == '?'){
                if(t[i] == '0'){
                    res++;
                }
                else {
                    num_q++;
                }
            } else if (s[i] == '1' && t[i] == '0'){
                num_one_zero++;
            } else if(s[i] == '0' && t[i] == '1'){
                num_zero_one++;
            }
        }

        int num_swap = min(num_one_zero, num_zero_one);
        num_one_zero -= num_swap;
        num_zero_one -= num_swap;

        res += num_swap;
        
        if(num_zero_one > 0){
            res += num_zero_one;
            res += num_q;
        } else if (num_one_zero > 0){
            if (num_q < num_one_zero) {
                res = -1;
            } else {
                res += 2 * num_q;
                res += (num_q - num_one_zero);
            }
        } else if(num_one_zero == 0 && num_zero_one == 0){
            res += num_q;
        }
        printf("Case %d: %d\n", k, res);
    }
}