// https://codeforces.com/problemset/problem/2259/D

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
    If we have 1 zero the answer is NO else the answer is YES

        - two zeros in two different sets : MEX = 1
        - non zero elments in one : MEX = 0

        MEX(A)+MEX(B)+MEX(C) >= 2*max(MEX(A), MEX(B), MEX(C))
           1  +  1  +  0     >=   2 * (1)
*/

void solve() {
    int z = 0, n;   cin >> n; 
    vector<int> carry(n);   for(auto &val : carry) {cin >> val; if(val==0)++z;}

    if(z == 1) {print_no;   return;}
    
    print_yes; z = 0; 
    for(int i = 0; i < n; i++) {
        if(carry[ i ] == 0) {
            z++;    
            if(z&1) cout << 'A'; else cout << 'B'; 
        } else cout << 'C';
    }
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

