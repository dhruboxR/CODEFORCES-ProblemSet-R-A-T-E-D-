// https://codeforces.com/problemset/problem/2216/B

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
#define rwhole(vect) (vect).rbegin(), (vect).rend()
#define print_yes (cout << "YES" << endl)
#define print_no (cout << "NO" << endl)
#define print_zero (cout << "0" << endl)
#define negative (cout << "-1" << endl)

void solve() {
    int ct, ch, cu;     cin >> ct >> ch >> cu;
    if( ct == 0 ) {int n = (cu * 3) + (ch * 3); cout << n << endl;  return;}

    int total = 0;

    // 1 T 1 U : 4 px
    if (ct > 0 && cu > 0 ) {
        int inf = min(ct, cu);      ct -= inf;      cu -= inf; 
        total += (4 * inf); 
    }

    // 2 T 1 H : 7 px
    if(ct > 1 && ch > 0) {
        if( ct > ch * 2) {
            total += (ch * 7);     ct -= (ch * 2);     ch = 0;
        } else {
            int takeT = (ct / 2) * 2; 
            total += (ct / 2) * 7;   ch -= (ct / 2);    ct -= takeT;
        }
    }

    // 1 T 1 H : 5px
    if(ct > 0 && ch > 0) {int inc = min(ct, ch);  total += inc * 5;   ct -= inc;    ch -= inc;}

    // only T 
    if(ct > 0) {total += (ct > 0 ? ((ct-1)*2)+3 : 0);}

    // only h and only u
    if(ch > 0 || cu > 0) {total += (ch * 3) + (cu * 3);}

    cout << total << endl;

    // NEED TO THINK SIMPLY  !! 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}