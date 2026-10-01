// https://codeforces.com/problemset/problem/2259/C

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
    int n;  cin >> n;  
    vector<int> source(n);  for(auto &val : source) cin >> val; 

    // mark the frst one 
    for(int i = 0; i < n; i++) {
        if(source[ i ] == -1) source[ i ] = 1; 
        if(source[ i ] == 1) break; 
    }
    // mark the last one 
    for(int i = n-1; i >= 0; i--) {
        if(source[ i ] == -1) source[ i ] = 1; 
        if(source[ i ] == 1) break; 
    }
    
    // the rest of the minus 1's becomes zero 0 
    for(auto &val : source) cout << max(val, 0ll) << " "; 
    cout << endl;
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

