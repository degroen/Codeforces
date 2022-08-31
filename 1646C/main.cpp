#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

int ones(ll x){
    int ans=0;
    while (x) ans+=x%2, x /= 2;
    return ans;
}

void solve(){
    ll n; cin >> n;
    vector<ll> fact(15);
    fact[0]=1;
    for (int i=1; i<15; i++)
        fact[i]=i*fact[i-1];
    map<ll, int> dp;
    dp[0] = 0;
    for (int i=3; i<15; i++) {
        auto tmp = dp;
        for (auto j = dp.begin(); j != dp.end(); j++)
            tmp[(*j).first + fact[i]] = (*j).second + 1;
        dp = tmp;
    }
    int k=INF;
    for (auto el:dp)
        if (n>=el.first)
            k = min(k, el.second+ones(n-el.first));
    cout << k << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}