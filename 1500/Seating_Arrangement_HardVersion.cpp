// https://codeforces.com/problemset/problem/2232/C2

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
    int n, table, seats;    cin >> n >> table >> seats; 
    string frndSequence;    cin >> frndSequence; 

    int empSeats = 0, passedAmbivert = 0, seated = 0; 

    for(int i = 0; i < n; i++) {
        // Introverts will acquire a empty table and seat 
        if( frndSequence[ i ] == 'I' ) {
            if( table ) {++seated;  --table;   empSeats += seats-1;}

        } else if( frndSequence[ i ] == 'A' ) {
            // If there are any empty seats, Ambivert friend goes and seats there
            if( empSeats ) {
                ++seated;   --empSeats;
                // This guy could have moved to a new table and seated there 
                ++passedAmbivert;
            } else {
                // There were no empty Seats
                if( table ) {
                    ++seated;   --table;    empSeats += seats - 1; 
                }
            }
        } else {
            // This is and Extrovert Friend 
            if( empSeats ) {
                --empSeats; ++seated; 
            } else {
                // There were no empty seats available 
                // If there were any AMBIVERT who went and seated on a empty seat,
                // He could have went and seated on a new table 
                if( passedAmbivert && table ) {
                    --passedAmbivert;   --table;
                    empSeats += seats;

                    // Now the EXTROVERT GUY CAN SEAT 
                    ++seated;   --empSeats;
                }
            }
        }
    }
    cout << seated << endl;
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