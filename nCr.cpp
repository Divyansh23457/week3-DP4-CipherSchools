#include <bits/stdc++.h>
using namespace std;

int computencr(int n, int r, int x)
{
    if (r > n - r)
        r = n - r;
    int dp[r + 1];
    for(int i = 0 ; i <=r ; i++)dp[i]=0;
    dp[0] = 1; 
    for (int i = 1; i <= n; i++) {
        for (int j = min(i, r); j > 0; j--)
            dp[j] = (dp[j] + dp[j - 1]) % x;
    }
    return dp[r];
}

int main()
{
    int n = 11, r = 2, x = 6;
    cout << "Value of nCr % x is " << computencr(n, r, x) <<endl;
    return 0;
}
