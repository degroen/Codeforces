#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int

void solve(){
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int sum=0;
    forn(i, n) {
        string s; cin >> s;
        forn(j, n)
            a[i][j] = s[j]-'0', sum += a[i][j];
    }
    int diag=0;
    forn(i, n) {
        int ones(0);
        forn(j, n) ones += a[j][(i+j)%n];
        diag = max(diag, ones);
    }
    cout << sum+n-2*diag << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}