// https://codeforces.com/problemset/problem/2255/A

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

// THE WHOLE GAME RESULT WILL BE DECIDED BASED ON ONLY 1 ROUND 
// HOLD EVERYTHING TILL THE FINAL ROUND & THEN PERFORM THE VALID TRANSFERS 

void solve() {
    int n, round;   cin >> n >> round;  n *= 2; 
    string potato;  cin >> potato; 
    string temp = potato; 

    for(int i = 0; i < n; i++) {
        if(i+1 < n) {
            if(potato[ i ] == '1' && potato[ i+1 ] == '0') {
                // we can transfer this to the next person 
                temp[ i ] = '0';    temp[ i+1 ] = '1';
            }
        } else {
            if(potato[ i ] == '1' && potato[ 0 ] == '0') {
                temp[ i ] = '0';    temp[ 0 ] = '1';
            }
        }
    }

    int oddRed = 0, blueEven = 0;
    for(int i = 0; i < n; i++) {
        
        blueEven += (i%2 == 0 && temp[ i ] == '1'); 
        
        oddRed += ((i&1) && temp[ i ] == '1');
    }
    cout << oddRed << " " << blueEven << endl;
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