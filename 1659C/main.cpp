#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

void solve(){
    int n, a, b; cin >> n >> a >> b;
    vector<int> x(n+1, 0);
    for (int i=1; i<=n; i++) cin >> x[i];
    vector<ll> sum(n+1, 0);
    for (int i=1; i<=n; i++) sum[i]=x[i]+sum[i-1];
    ll ans=0;
    for (int i=1; i<=n; i++)
        ans = min(ans, (ll)a*x[i]-(ll)b*x[i]*(n-i)-b*sum[i-1]);
    cout << ans+b*sum[n] << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}