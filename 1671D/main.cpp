#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, x; cin >> n >> x;
    vector<int> a(n);
    int min_val(1e9), max_val(0);
    for (int i=0; i<n; i++){
        cin >> a[i];
        min_val = min(min_val, a[i]), max_val=max(max_val, a[i]);
    }
    long long int ans=0;
    for (int i=0; i+1<n; i++)
        ans += abs(a[i]-a[i+1]);
    if (min_val>1) ans += min(min(a[0]-1, a[n-1]-1), 2*min_val-2);
    if (x>max_val) ans += min(min(x-a[0], x-a[n-1]), 2*x-2*max_val);
    cout << ans << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}