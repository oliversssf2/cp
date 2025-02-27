#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long dp[20][20][20];
    memset(dp,0,sizeof(dp));

    dp[1][1][1] = 1;
    for(long long n = 2; n < 14 ; n++)
    for(long long p = 1; p <= n; p++)
    for(long long r = 1; r <= n; r++){
        long long middle = dp[n-1][p][r] * (n-2);
        long long front = dp[n-1][p-1][r];
        long long back = dp[n-1][p][r-1];
        dp[n][p][r] = middle + front + back;
    }

    long long t; cin >> t;
    while(t--){
        long long n, p, r;
        cin>>n>>p>>r;
        cout << dp[n][p][r] << endl;
    }
}   
