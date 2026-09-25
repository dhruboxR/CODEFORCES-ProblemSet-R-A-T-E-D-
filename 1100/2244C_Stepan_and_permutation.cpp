// https://codeforces.com/problemset/problem/2244/C

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
    Sroting is always possible if the , difference % gcd == 0 

        difference = (final position - initial position)
        gcd = gcd(x, y)
*/

void solve() {
    int n, x, y;    cin >> n >> x >> y;
    vector<int> values(n);  for(auto &x : values) cin >> x; 

    int gc = gcd(x, y);
    for(int i = 0; i < n; i++) {
        if(values[ i ] != i+1) {
            // not in the correct position 
            int diff = abs(values[i] - (i+1)); 

            if(diff % gc) {print_no;    return;}
        }
    } 
    print_yes;
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