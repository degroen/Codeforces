#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int

void solve(){
    int n; cin >> n;
    vector<int> a(n+1, 0);
    for (int i=2; i<=n; i++){
        int tmp; cin >> tmp;
        a[tmp]++;
    }
    sort(a.begin(), a.end());
    int par_num = a.end()-upper_bound(a.begin(), a.end(), 0) +1;
    if (par_num>=a[n]){
        cout << par_num << endl;
        return;
    }
    int ans=0;
    multiset<int> mul;
    for (int i=n; i>=0; i--)
        if (a[i]) mul.insert(a[i]-par_num+n-i);
    while (ans<*mul.rbegin()){
        int col=*mul.rbegin();
        mul.erase(mul.find(col));
        mul.insert(col-1);
        ans++;
    }
    cout << par_num+ans << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}