// https://codeforces.com/contest/2229/problem/C2

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
    int length;     cin >> length;      vector<int> source(length), presum(length);
    for(int i = 0; i < length; i++) {
        cin >> source[ i ]; 
        presum[ i ] = (i == 0 ? source[ i ] : presum[ i-1 ] + source[ i ]);
    }
    
    int idx = -1, mods = 0, mx = presum.back();
    for(int i = 0; i < length; i++) {
        if(source[ i ] > 0) {
            // if we make this negative | previous elements becomes positive
            // total sum (i-1)elements positive + (i negative) + rest

            int currs = presum.back() - presum[ i ] + mods - source[ i ];     

            if(currs > mx) {
                idx = i;
                mx = currs;
            }
        }
        mods += abs( source[ i ]);
    }

    // operations

    if( idx <= 0 ) {
        cout << 0 << endl << endl;      // no operations 
    } else {
        int state = 1;  vector<int> opidx;

        for(int i = idx-1; i >= 0; i--) {
            int currs = source[ i ] * state; 
            if( currs > 0 ) {
                opidx.push_back( i+1 );   state *= -1;
            }
        }
        opidx.push_back( idx+1 );     // last operation on the marked index thus previous all elements becomes positive

        cout << opidx.size() << endl; 
        for(auto val : opidx) cout << val << " ";   cout << endl;
    }
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