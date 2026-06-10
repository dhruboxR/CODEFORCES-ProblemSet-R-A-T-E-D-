// https://codeforces.com/problemset/problem/2233/C

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
    we want to delete at most k characters so that,
    the remaining string has as few matched pairs as possible.

    Find the position p after which the balance is minimum.
        - before p (A) we prefer deleting '('
        - after  p (B) we prefer deleting ')'
        
    Every deleted character reduces the maximum possible number of matched pairs by exactly one.
*/

void solve() {
    int length, k;  cin >> length >> k; 
    string sequence;    cin >> sequence; 

    int p = 0, acm = 0, curr = 0;              // index where the balance is minimum 
    for(int i = 0; i < length; i++) {
        curr += (sequence[ i ] == '(' ? 1 : -1); 
        if( curr < acm ) {
            acm = curr; p = i+1;
        }
    }

    string fin(length, '0');
    for(int i = 0; i < length && k; i++) {
        if( (i < p && sequence[ i ] == '(') || (i >= p && sequence[ i ] == ')') ) {
            fin[ i ] = '1'; --k;
        }
    }
    cout << fin << endl;
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