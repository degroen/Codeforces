#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    forn (i, n) cin >> a[i];
    vector<ll> pre_sum(n+1, 0);
    forn (i, n) pre_sum[i+1]=pre_sum[i]+a[i];
    vector<ll> max_sum(n+1, -INF);
    for (int i=0; i<=n; i++)
        for (int j=0;j+i<=n; j++)
            max_sum[i] = max(max_sum[i], pre_sum[j+i]-pre_sum[j]);
    vector<ll> l(n+1, 0), r(n+1, max_sum[n]);
    forn (i, n) l[i+1] = max(l[i], max_sum[i+1]+x*(i+1));
    for (int i=n; i>0; i--)
        r[i-1] = max(r[i], max_sum[i]);
    forn (k, n+1)
        cout << max(l[k], r[k]+k*x) << " ";
    cout << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}