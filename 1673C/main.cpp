#include <bits/stdc++.h>
using namespace std;

int reverse(int x){
    int ans = 0;
    while(x)
        ans = ans*10+x%10, x /= 10;
    return ans;
}

int main() {
    //freopen("test.txt", "r", stdin);
    vector<int> pol;
    const int MOD = 1e9+7;
    int n=40000;
    for (int i=1; i<=n; i++)
        if (i==reverse(i))
            pol.push_back(i);
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(auto el:pol)
        for (int i=el; i<=n; i++)
            if (dp[i-el])
                dp[i] = (dp[i]+dp[i-el])%MOD;
    int t; cin >> t;
    while(t--) {
        cin >> n;
        cout << dp[n] << endl;
    }
    //fclose(stdin);
    return 0;
}