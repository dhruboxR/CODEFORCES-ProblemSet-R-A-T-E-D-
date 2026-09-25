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

// IMPLEMENTATION BASED PROBLEM 

void solve() {
    int n;  cin >> n;   vector<int> shadow(n), sval;  map<int, int> freq; 
    for(int i = 0; i < n; i++) {
        cin >> shadow[ i ];     
        if( !freq.count(shadow[i]) ) sval.push_back(shadow[i]); 

        freq[ shadow[i] ]++;
    }
    sort( whole(sval) ); 

    if(!freq.count(0)) {negative;   return;}    // if no 0 present then invalid 

    // if there is only one distinct shadow 
    if(freq.size() == 1) {
        for(int i = 0; i < n; i++) cout << 1 << " "; 
        cout << endl;   return;
    }

    // recover the original values and map to corresponding shadow 
    map<int, int> ans; 

    for(int i = 0; i < sval.size(); i++) {
        // this is the last value 
        if(i == sval.size() - 1) {
            ans[ sval[i] ] = ans[ sval[i-1] ] + 1; 
        } else {
            int diff = sval[ i+1 ] - sval[ i ]; 

            // original value must be integer 
            if(diff % freq[ sval[i] ]) {negative;    return;}

            ans[ sval[i] ] = diff / freq[ sval[i] ]; 

            // original values must be strictly increasing 
            if(i > 0 && ans[ sval[i] ] <= ans[ sval[i-1] ]) {negative;    return;}
        }
    }

    for(int i = 0; i < n; i++) {
        cout << ans[ shadow[i] ] << " "; 
    } cout << endl;
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