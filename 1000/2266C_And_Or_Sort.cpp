// https://codeforces.com/problemset/problem/2266/C

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
        - Test all split points where the string transitions from 0's to 1's 
    - A split after index k means the first k elements must be '0' and the remaining must be '1'

        - turn ones on the left into zeros (count of 1's till now)
        - turn zeros on the right into ones (zero's on the right)
*/

void solve() {
    int n;  cin >> n;   string s;   cin >> s; 
    
    int cZero = count(whole(s), '0'); 
    int cOne = count(whole(s), '1'); 

    if(s.front() == '1') {cout << cZero << endl;    return;}

    int onesOnLeft = 0, move = LLONG_MAX; 

    for(int i = 0; i < n; i++) {
        if(s[i] == '1') onesOnLeft++; 

        int zerosOnRight = cZero - (i+1 - onesOnLeft); 

        move = min(move, onesOnLeft + zerosOnRight); 
    }
    cout << move << endl; 
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