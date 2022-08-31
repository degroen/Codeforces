#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i=0; i<n; i++)
#define all(v) v.begin(), v.end()

void solve(){
    int n; cin >> n;
    multiset<int> a;
    forn(i, n) {
        int tmp; cin >> tmp;
        while (!(tmp&1)) tmp /= 2;
        a.insert(tmp);
    }
    bool ans=true;
    forn(_, n){
        int tmp; cin >> tmp;
        while (tmp && a.find(tmp)==a.end())
            tmp /= 2;
        if (tmp==0) ans=false;
        else a.erase(a.find(tmp));
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while (t--) solve();
    //fclose(stdin);
    return 0;
}