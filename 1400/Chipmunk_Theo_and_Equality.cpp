// https://codeforces.com/problemset/problem/2231/C

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
    We can observe that every element can either become 1 or 2 or some x in the process
    - total operations for each element to become 1 
    - total operations for each element to become 2
    - total operations for each element to become x

    For each element x,
    - the occurance of x should be n for it to become a potential answer
    - each every value must become x during the operations
*/

void solve() {
    int n;  cin >> n;   int source[ n ];    for(int i = 0; i < n; i++) cin >> source[ i ];
    map<int, int> operation, possible;

    set<int> eligible;  // only the path that the smallest number goes through [ saves TLE ]
    eligible.insert( 1 ); eligible.insert( 2 );
    
    int curr = source[ 0 ];
    while( curr != 1 ) {
        eligible.insert( curr );

        if(curr&1) ++curr;  else curr >>= 1;
    }

    for(int i = 0; i < n; i++) {
        int current = source[ i ];
        if( source[ i ] == 1 ) {
            ++possible[ 1 ];    ++possible[ 2 ];
            ++operation[ 2 ];
            continue;
        }
        // greater than 1 
        int cop = 0;
        while( current != 1 ) {
            if( eligible.count(current) ) {
                ++possible[ current ];  operation[ current ] += cop;
            }
            if(current&1) ++current;
            else current >>= 1;     // dividing by 2 

            cop++;
        }
        possible[ 1 ]++;
        operation[ 1 ] += cop;
    }
    int ans = LLONG_MAX;
    for(auto [ key, value ] : possible) {
        if(value == n) ans = min(ans, operation[ key ]);
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