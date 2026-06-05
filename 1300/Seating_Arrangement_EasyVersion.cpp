// https://codeforces.com/problemset/problem/2232/C1

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
    int friends, table, seats;  cin >> friends >> table >> seats;
    int seated = 0, emptySeat = 0, prevAmbivert = 0;

    string seq;     cin >> seq;

    for(int i = 0; i < friends; i++) {
        // Introverts will acquire a empty table and seat
        if( seq[ i ] == 'I' ) {
            if( table ) {++seated;  --table;   emptySeat += seats-1;}
        }
        else if( seq[ i ] == 'A' ) {
            // if there are empty seats Ambivert will go and seat there 
            if( emptySeat ) {
                ++seated;   --emptySeat;    
                // this guy could have seated on a new Table as the first person 
                ++prevAmbivert;     
            } else {
                // there was no empty seats 
                if( table ) {
                    --table;    ++seated;   emptySeat += seats-1;
                }
            }
        } else {
            // This is an Extrovert guy if there is any empty seat on a table he goes and seats there 
            if( emptySeat ) {
                --emptySeat;    ++seated;
            } else {
                // There was no empty seats available 
                // if there were any AMBIVERT who went and seated on a empty seat, 
                // he could have gone to an empty table and have a seat there 
                if(prevAmbivert && table) {
                    --prevAmbivert;     --table;    
                    emptySeat += seats;

                    // now the EXTROVERT GUY CAN SEAT THERE 
                    ++seated;   --emptySeat;
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