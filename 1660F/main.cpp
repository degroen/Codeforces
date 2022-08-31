#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int
#define all(v) v.begin(),v.end()
const int INF = INT_MAX >> 1;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vector<int> sum(n+1, 0);
    forn(i, n) sum[i+1]=sum[i]+(s[i]=='+' ? 1: -1);
    vector<int> p(n+1, 0);
    for (int i=2; i<=n; i++)
        if (s[i-1]=='-' && s[i-2]=='-')
            p[i] = p[i-2]+1;
        else p[i]=p[i-1];
    ll ans=0;
    forn(i, n){
        for (int j=i+1; j<=n; j++){
            int bal=sum[j]-sum[i], ch=p[j]-p[i];
            if (bal<=0 && bal+3*ch>=0 && (-bal)%3==0)
                ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}