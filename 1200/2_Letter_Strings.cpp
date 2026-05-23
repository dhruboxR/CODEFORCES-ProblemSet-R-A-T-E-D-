// https://codeforces.com/contest/1669/problem/E

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

//     Iterate through all given strings 
//     Generate all strings that differ in exactly one position, 
//     Count the number of times these strings occur in the array.

void solve() {
    int length;     cin >> length; 
    map<string, int> occurance;

    int totalPair = 0;

    for(int i = 0; i < length; i++) {
        string current;     cin >> current;
        occurance[ current ]++;

        // change the first character [ from 'a' till 'k' ]
        for(char c = 'a'; c <= 'k'; c++) {
            if( current[ 0 ] == c ) continue;

            string temp = current;  temp[ 0 ] = c;
            totalPair += occurance[ temp ];
        }
        // change the second character [ from 'a' till 'k' ]
        for(char c = 'a'; c <= 'k'; c++) {
            if( current[ 1 ] == c ) continue;

            string temp = current;  temp[ 1 ] = c;
            totalPair += occurance[ temp ];
        }
    }
    cout << totalPair << endl;
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
