// https://codeforces.com/problemset/problem/1401/C

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
    LET'S TAKE GCD WITH THE MINIMUM ELEMENT AND MARK THAT POSITION  

    - i'th          :   4   3   6   6   2   9       here min element is 2 
    - gcd(ith, 2)   :  -1   3  -1  -1  -1   9       we have [ 4, 6, 6, 2 ] as swap options

    sort the swapOptions [4, 6, 6, 2] -> [ 2, 4, 6, 6 ] 
    Then whenever we find a -1 in the source we put value from options in order 
*/

void solve() {
    int n;  cin >> n; 
    vector<int> source(n);  for(auto &val : source) cin >> val;
    int mn = *min_element( whole(source) );

    multiset<int> options; 
    for(int i = 0; i < n; i++) {
        if( gcd(source[ i ], mn) == mn ) {
            options.insert( source[ i ]);
            source[ i ] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        if( source[ i ] == -1 ) {
            source[ i ] = *options.begin();
            options.erase( options.begin() );
        }
    }
    if(is_sorted( whole(source) )) print_yes;   else print_no;
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