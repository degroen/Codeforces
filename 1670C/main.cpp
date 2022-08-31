#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
const int MOD=1e9+7;

void rec(const vector<vector<int>>& graf, vector<bool>& used, int node){
    if (used[node]) return;
    used[node]=true;
    for (auto el:graf[node])
        rec(graf, used, el);
}

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    forn(i, n) cin >> a[i];
    forn(i, n) cin >> b[i];
    vector<vector<int>> graf(n+1);
    forn(i, n) graf[a[i]].push_back(b[i]), graf[b[i]].push_back(a[i]);
    vector<bool> used(n+1, false);
    forn(i, n){
        int tmp; cin >> tmp;
        rec(graf, used, tmp);
    }
    ll ans=1;
    forn(i, n) {
        if (!used[a[i]] && a[i]!=b[i])
            ans = (ans * 2) % MOD;
        rec(graf, used, a[i]);
    }
    cout << ans << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}