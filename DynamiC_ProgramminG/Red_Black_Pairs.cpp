// https://codeforces.com/problemset/problem/2225/C

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

// dp[ i ] = minimum number of cells to repaint to make a pair

void solve() {
    int n;      cin >> n;
    string row1, row2;  cin >> row1 >> row2;

    vector<int> dp(n, INT_MAX);
    for(int i = 0;  i < n; i++) {
        // vertically   
        int vertical = (row1[ i ] != row2[ i ]) + (i ? dp[ i-1 ] : 0);
        dp[ i ] = vertical;

        // horizontally 

        if( i ) {
            int horizontal = (row1[ i ] != row1[ i-1 ]) + 
                             (row2[ i ] != row2[ i-1 ]) +
                             (i >= 2 ? dp[ i-2 ] : 0);

            dp[ i ] = min(dp[ i ], horizontal);
        }
    }
    cout << dp.back() << endl;
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