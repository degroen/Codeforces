#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

void rec(map<ll, int>& a, ll sum, int& step){
    if (a[sum]){
        a[sum]--;
        return;
    }
    step--;
    if(step<=0) return;
    rec(a, floor(sum/2.0), step);
    rec(a, ceil(sum/2.0), step);
}

void solve(){
    int n; cin >> n;
    map<ll, int> a;
    ll sum=0;
    forn(_, n){
        int tmp; cin >> tmp;
        a[tmp]++; sum+=tmp;
    }
    int step=n;
    rec(a, sum, step);
    for (auto el:a) if (el.second){
        cout << "NO\n"; return;
    }
    cout << "YES\n";
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}