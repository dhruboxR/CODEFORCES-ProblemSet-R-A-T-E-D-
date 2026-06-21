// https://codeforces.com/contest/1883/problem/F
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
    How many pairs (first occurrence position, last occurrence position) exist 
        such that first ≤ last"
*/
void solve() {
    int n;  cin >> n;   vector<int> src(n);
    set<int> first_occurance, store;   map<int, int> last_occurance;

    for(int i = 0; i < n; i++) {
        int val;    cin >> val; 
        src[ i ] = val;

        // value appearing for the first time in the array 
        if( store.count(val) == 0 ) first_occurance.insert(i);
        store.insert(val);

        last_occurance[ val ] = i;  // last occurance of the value 
    }   
    // traverse in reverse 
    int ans = 0, cnt = 0; 
    for(int i = n-1; i >= 0; i--) {
        if(last_occurance[ src[ i ] ] == i) ++cnt;  // number of valid "right endpoints" seen so far
        
        if(first_occurance.count(i)) ans += cnt;    
            // So for each valid l, you count how many valid r ≥ l.
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