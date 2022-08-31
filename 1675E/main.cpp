#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n, k; cin >> n >> k;
    string s; cin >> s;
    char last=0;
    int m=0;
    for (int i=0; i<n; i++){
        if (!last && k>=s[i]-'a') m=max(m, s[i]-'a'), s[i]='a';
        else if(!last) last=s[i];
        if (s[i]-'a'<=m) s[i]='a';
        if (s[i]<=last && s[i]>=last+m-k) s[i]=last+m-k;
    }
    cout << s << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}