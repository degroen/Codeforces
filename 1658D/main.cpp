#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int

void solve(){
    int l, r; cin >> l >> r;
    int n=r-l+1;
    vector<int> a(n);
    forn(i, n) cin >> a[i];
    int ans(0);
    for (int i=0; i<17; i++){
        int ones1(0), ones2(0);
        for (int num=l; num<=r; num++)
            if ((1<<i)&num) ones1++;
        for (auto el:a)
            if ((1<<i)&el) ones2++;
        if (ones1!=ones2)
            ans += (1<<i);
    }
    cout << ans << endl;
}

int main() {
    freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    fclose(stdin);
    return 0;
}