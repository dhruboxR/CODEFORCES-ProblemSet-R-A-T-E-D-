// https://codeforces.com/problemset/problem/2218/E

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
We have an array a=[a1,a2,a3,…,an]
Suppose we performed the operations from left to right, to see how operations affect the array.

After the first operation, the array becomes: 
    a = [ a2 ⊕ a1 , a3 ⊕ a1, ......, an ⊕ a1 ]      -> Note that the first element was removed.

After the second operation, the array becomes 
    a = [ (a3⊕a1)⊕(a2⊕a1), ....... ,(an⊕a1)⊕(a2⊕a1) ]

This is the same as a=[a3⊕a2,…,an⊕a2]

        XOR PROPERTIES :
            5 ⊕ 5 = 0 || x1 ⊕ x2 = 0

                (a3⊕a1) ⊕ (a2⊕a1)
            => a3 ⊕ a1 ⊕ a2 ⊕ a1    [ a1 negates each other out ]
            remains => a3 ⊕ a2
*/

void solve() {
    int length;     cin >> length; 
    vector<int> source(length);     for(auto &val : source) cin >> val;

    int mx = LLONG_MIN; 

    // find the single element with whom the xor result is maximum ! we keep it for the end 
    for(int i = 0; i < length; i++) {
        for(int j = 0; j < length; j++) {
            int val = source[ i ] ^ source[ j ];
            mx = max(val, mx);
        }
    }
    cout << mx << endl; 
}

// the constarins are low n(2 ≤ n ≤ 3105) -> O( n2 ) = 9e6 [ we can go up to 1e9 !! ] 

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}