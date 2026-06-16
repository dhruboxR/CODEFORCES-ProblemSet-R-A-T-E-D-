// https://codeforces.com/contest/450/problem/B
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
f1 = x
f2 = y
f3 = y - x
f4 = (y - x) - y    = -x
f5 = -x - (y - x)   = -y
f6 = -y - (-x)      = x - y
f7 = (x - y) - (-y) = x

Sequence repeats every 6 terms:

[x, y, y - x, -x, -y, x - y]

Therefore:
f(n) = sequence[(n - 1) % 6]
*/

void solve() {
    int x, y, n;    cin >> x >> y >> n; 

    const int MOD = 1e9+7;
    int f[6];

    f[0] = x;
    f[1] = y;
    f[2] = y - x;
    f[3] = -x;
    f[4] = -y;
    f[5] = x - y;
    /*
         Negative modulo handling
         Values such as -x or -y may be negative. The final answer must be in [0, MOD-1].
    */
    long long ans = f[(n - 1) % 6];

    ans = (ans % MOD + MOD) % MOD;

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}