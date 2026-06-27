// https://codeforces.com/problemset/problem/1692/F

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
    Only the last digit matters because we only care whether the sum ends with 3. So, 
        - Replace eveery number by number % 10 
        - We only have 10 possible digits[ 0-9 ]

    Also we never need more than 3 occurances fo the same last digit, 
    Since we are choosing only 3 numbers
*/

void solve() {
    int len;    cin >> len; 
    vector<int> freq(10, 0), source;

    for(int i = 0; i < len; i++) {
        int number; cin >> number; 

        int v = number %= 10;       // extract the last digit 

        if(freq[ v ] < 3) source.push_back(v);
        freq[ v ]++;
    }

    // traverse the source : B R U T E F O R C E 
    for(int i = 0; i < source.size(); ++i) {
        int a = source[ i ];

        for(int j = 0; j < source.size(); ++j) {
            if(j == i) continue; 
            int b = source[ j ];

            for(int k = 0; k < source.size(); ++k) {
                if(k == i || k == j) continue;
                int c = source[ k ];

                if((a + b + c) % 10 == 3) {print_yes;   return;}
            }
        }
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