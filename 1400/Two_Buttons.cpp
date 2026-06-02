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
    int curr, tar;  cin >> curr >> tar;
    if(curr == tar) print_zero; 
    else if( curr > tar ) cout << curr - tar << endl;
    else {
        // reverse : from target to current 
        int move = 0; 
        while( tar > curr ) {
            if( tar&1 ) tar++;  else tar /= 2;
            move++;
        }
        move += (curr - tar);   // we are decreasing the target, so it might go below current
        cout << move << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}