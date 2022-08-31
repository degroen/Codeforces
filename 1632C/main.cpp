#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

void solve(){
    int a, b; cin >> a >> b;
    int ans=b-a;
    for (int i=a; i<=b; i++)
        ans = min(ans, i-a+1+i|b-b);
    cout << ans << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}