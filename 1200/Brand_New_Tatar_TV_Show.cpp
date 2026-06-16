// https://codeforces.com/problemset/problem/2236/D

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
    n = 9, k = 2 
    1 2 3   7   10 11   15 17 18
*/

// If there are 2 distinct elements present in any block egor will win 
// If there are only 1 distinct element then the size of that block should be even for egor to win

void solve() {
    int n, k;   cin >> n >> k; 
    vector<int> source(n);  for(auto &val : source) cin >> val; 
    sort( whole(source) );

    vector<vector<int>> blocks;     vector<int> temp;   temp.push_back(source[ 0 ]);
    for(int i = 1; i < n; i++) {
        if(source[ i ] - source[ i-1 ] <= k) temp.push_back(source[ i ]);
        else {
            blocks.push_back( temp );   temp.clear();
            temp.push_back(source[ i ]);
        }
    }
    if(!temp.empty()) blocks.push_back(temp);

    // if at any block we get two distinct element
    auto distinct = [ & ](vector<int>curr) -> bool {
        set<int> s;     for(auto &val : curr) s.insert(val);

        if(s.size() == 1 && curr.size() % 2 == 0) return true;  // even occurance of mx

        return s.size() > 1;
    };

    for(int i = 0; i < blocks.size(); i++) {
        if( distinct( blocks[ i ] ) ) {print_yes;   return;}
    }
    print_no;
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