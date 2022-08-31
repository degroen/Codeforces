#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

void solve(){
    int n, k; cin >> n >> k;
    vector<int> b(n), c(n);
    forn (i, n) cin >> b[i];
    forn (i, n) cin >> c[i];
    vector<int> cost(1001, INF);
    cost[1] = 0;
    for (int i=1; i<=1000; i++)
        for (int x=1; x<=1000; x++)
            if (i+floor((double)i/x)<=1000)
                cost[i+floor((double)i/x)] = min(cost[i+floor((double)i/x)], cost[i]+1);
    if (k>=n*12){
        ll ans=0;
        forn (i, n) ans+=c[i];
        cout << ans << endl;
        return;
    }
    vector<ll> dp(k+1, -1);
    dp[0] = 0;
    forn (i, n)
        for (int j=k-cost[b[i]]; j>=0; j--)
            if (dp[j]!=-1)
                dp[j+cost[b[i]]] = max(dp[j+cost[b[i]]], dp[j]+c[i]);
    ll ans=0;
    forn (i, k+1) ans = max(ans, dp[i]);
    cout << ans << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}