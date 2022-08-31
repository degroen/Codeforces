#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

void solve(){
    int n, m; cin >> n >> m;
    map<int, vector<int>> x, y;
    forn(i, n) forn(j, m){
        int tmp; cin >> tmp;
        x[tmp].push_back(i);
        y[tmp].push_back(j);
    }
    ll ans=0;
    for (auto& [_, vec]:x){
        ll sum=0;
        sort(all(vec));
        forn(i, vec.size())
            ans+=vec[i]*i-sum, sum += vec[i];
    }
    for (auto& [_, vec]:y){
        ll sum=0;
        sort(all(vec));
        forn(i, vec.size())
            ans+=(ll)vec[i]*i-sum, sum += vec[i];
    }
    cout << ans << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t(1);
    while(t--) solve();
    //fclose(stdin);
    return 0;
}