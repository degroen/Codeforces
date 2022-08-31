#include <bits/stdc++.h>
using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ll long long int

void solve(){
    int n; cin >> n;
    vector<int> a(n+1, 0);
    forn(i, n) cin >> a[i];
    int max_two(0), l=n, r=0;
    int sign(1), two(0), beg(0), first_min=-1, last_min=-1;
    for (int i=0; i<=n; i++){
        if (abs(a[i])==2) two++;
        if (a[i]<0) sign ^= 1, last_min=i;
        if (a[i]<0 && first_min==-1) first_min=i+1;
        if (a[i]==0){
            if (two>max_two && sign)
                max_two = max(max_two, two), l=beg, r=n-i;
            if (!sign && first_min!=-1){
                two=0;
                for (int j=beg; j<last_min; j++)
                    if (abs(a[j])==2) two++;
                if (two>max_two)
                    max_two = max(max_two, two), l=beg, r=n-last_min;

                two=0;
                for (int j=first_min; j<i; j++)
                    if (abs(a[j])==2) two++;
                if (two>max_two)
                    max_two = max(max_two, two), l=first_min, r=n-i;
            }

            two=0, sign=1, beg=i+1, first_min=-1;
        }
    }
    cout << l << " " << r << endl;
}

int main() {
    //freopen("test.txt", "r", stdin);
    int t; cin >> t;
    while(t--) solve();
    //fclose(stdin);
    return 0;
}