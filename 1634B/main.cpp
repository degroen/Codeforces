#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

void solve(){
    int n;
    ll x, y;
    cin >> n >> x >> y;
    x = x&1, y = y&1;
    forn(_, n){
        int tmp; cin >> tmp;
        tmp = tmp&1;
        x = x^tmp;
    }
    if (x==y)
        cout << "Alice\n";
    else
        cout << "Bob\n";
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}