#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

void solve(){
    int n, k; cin >> n >> k;
    if (k==n-1){
        if (n==4) {
            cout << "-1\n";
            return;
        }
        vector<bool> used(n, false);
        used[0] = true;
        used[1] = true;
        used[n/2-1] = true;
        cout << 0 << " " << n/2-1 << endl;
        cout << 1 << " " << n-1 << endl;
        for (int i=1; (1<<i)<n; i++){
            cout << (1<<i) << " " << ((1<<(i-1))^(n-1)) << endl;
            used[1<<i] = true;
        }
        for (int i=3; i<n/2; i++)
            if (!used[i])
                cout << i << " " << (i^(n-1)) << endl;
        return;
    }
    cout << k << " " << n-1 << endl;
    if (k)
        cout << 0 << " " << ((n-1)^k)<< endl;
    for (int i=1; i<n/2; i++)
        if (i!=k && i!=((n-1)^k))
            cout << i << " " << (i^(n-1)) << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}