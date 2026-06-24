// https://codeforces.com/problemset/problem/2223/A

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

bool isValid(string &sequence) {
    int balance = 0;  
    for(char cherr : sequence) {
        if(cherr == '(') ++balance; else --balance;  
        
        if(balance < 0) return false;   // ')' came before '('
    }

    return balance == 0;        // balance must be 0 at the for RBS
}

void solve() {
    int n;  cin >> n;   string a, b;    cin >> a >> b; 
    /*
        NUMBER OF POSITIONS WHERE a[ i ] != b[ i ]
            
            For such positions :
            odd flexible positions gets   -> '('
            even flexible positions gets  -> ')'
    */

    int cnt = 0;
    for(int i = 0; i < n; i++) {
        // Fixed position, where swapping does nothing 
        if(a[ i ] == b[ i ]) continue;

        ++cnt; 

        if(cnt&1) {
            a[ i ] = '(';   b[ i ] = ')';
        } else {
            a[ i ] = ')';   b[ i ] = '(';
        }
    }
    // Finally check if both string are Regular Bracket Sequence 
    if( isValid(a) && isValid(b)) print_yes; 
    else print_no;
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