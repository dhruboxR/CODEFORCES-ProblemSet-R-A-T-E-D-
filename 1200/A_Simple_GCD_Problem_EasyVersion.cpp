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

//           N U M B E R    T H E O R Y
/*
    For any two values a and b [ gcd(a,b) = x ]
        - we can change a value while keeping the gcd same if the new value is also divisible by X
        - new value is LCM(a,b)
*/

void solve() {
    int len;    cin >>  len;    vector<int> a(len), b(len);
    for(auto &v : a) cin >> v;  for(auto &v : b) cin >> v;

    int ans = (a.front() != gcd(a[0], a[1])) + (a.back() != gcd(a[len-1], a[len-2]));

    for(int i = 1; i < len-1; i++) {
        int leftGcd = gcd(a[ i ], a[ i-1 ]), rightGcd = gcd(a[ i ], a[ i+1 ]);
        int mul = lcm(leftGcd, rightGcd);

        ans += (mul != a[ i ]);
    }
    cout << ans << endl;
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