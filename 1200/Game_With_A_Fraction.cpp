// https://codeforces.com/contest/2197/problem/C

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
/*
        Define: d = y − x ||  Then the target stat  becomes: x = 2d, y = 3d

    //     -So the problem reduces to:
    //          Can the current state still “fit” into a scaled version of the target line?

    //     -Winning region idea

    //    Bob wins if current state is large enough to still reach: (2d,3d)

    //     -So condition: x ≥ 2d and y ≥ 3d means:
    //       The state lies inside a feasible cone leading to the ratio line
*/
void solve() {
    int p, q;   cin >> p >> q; 
    if( p >= q) {cout << "Alice" << endl;   return;}

    int diff = q - p;

    if((p >= 2*diff) && (q >= 3*diff)) cout << "Bob" << endl;
    else cout << "Alice" << endl;
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