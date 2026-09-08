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

// THIS PROBLEM MAN !!! takes a lot of time before starts making sense -_-

void solve() {
    int n;  cin >> n;   string s;   cin >> s; 

    auto flip = [ & ](char cherr) -> char {
        return cherr == '1' ? '0' : '1';      // flips 0 -> 1 and 1 -> 0
    };
    /*   We first process positions 0, 2, 4, 6...
            - For these positions:
            - s[i] must be different from s[i+2].
        So if we know one value, we can determine all other values two positions away  */
    
        for(int i = 0; i < n; i+=2) {
            if(s[ i ] == '?') continue;  // Found a known character to use as a string starting point 

            // Fill unknown characters going backwards 
            for(int j = i-2; j >= 0; j-=2) {
                if(s[ j ] == '?') s[ j ] = flip(s[ j+2 ]); // it must be opposite to s[j+2]
                else if(s[ j ] == s[ j+2 ]) {print_zero;    return;} 
            }

            // Fill the unknown characters going forwards 
            for(int j = i+2; j < n; j+=2) {
                if(s[ j ] == '?') s[ j ] = flip(s[ j-2 ]);
                else if(s[ j ] == s[ j-2 ]) {print_zero;    return;}
            }

            break;
        }

        /* Now process positions 1, 3, 5, 7, ...This group is independent from the previous group.*/
        for(int i = 1; i < n; i+=2) {
            if(s[ i ] == '?') continue; 

            for(int j = i-2; j >= 0; j-=2) {
                if(s[ j ] == '?') s[ j ] = flip(s[ j+2 ]);
                else if(s[ j ] == s[ j+2 ]) {print_zero;    return;}
            }

            for(int j = i+2; j < n; j+=2) {
                if(s[ j ] == '?') s[ j ] = flip(s[ j-2 ]);
                else if(s[ j ] == s[ j-2 ]) {print_zero;    return;}
            }

            break;
        }
        // s[0] and s[1] determine the entire string.
        //
        // If s[0] is already known:
        //     only 1 possibility.
        //
        // If s[0] is still '?':
        //     it can be either 0 or 1 -> 2 possibilities.
        //
        // Same logic applies to s[1].
        int ans = (s[0] == '?' ? 2 : 1) * (s[1] == '?' ? 2 : 1); 
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