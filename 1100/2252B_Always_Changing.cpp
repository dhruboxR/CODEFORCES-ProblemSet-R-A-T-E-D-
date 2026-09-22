// https://codeforces.com/contest/2252/problem/B

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
    int n;  cin >> n;   string s;   cin >> s;

    // count how many 0's & 1's needed to be deleted to make the string alternating 
    int delZero = 0, delOne = 0; 
    for(int i = 1; i < n; i++) {
        if(s[ i ] == s[ i-1 ]) {
            if(s[ i ] == '0') ++delZero; 
            else ++delOne; 
        }
    }
    int move = delZero + delOne; 
    // deletion satisfy the alternating rule 
    if( abs(delZero - delOne) <= 1 ) {cout << move << endl; return;}

    // Else we need to delete some additional characters that was deleted less 
    // The additional deletion can only be made from the two endpoints

    if(delZero > delOne) {
        // Delete additional 1's 
        int delExtra = abs(delZero - delOne) - 1; 
        int available = (s[0] == '1') + (s[n-1] == '1');

        if(available >= delExtra) cout << move + delExtra << endl; 
        else negative; 

    } else {
        // Delete additional 0's 
        int delExtra = abs(delZero - delOne) - 1; 
        int available = (s[0] == '0') + (s[n-1] == '0'); 

        if(available >= delExtra) cout << move + delExtra << endl; 
        else negative; 
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