https://codeforces.com/contest/2258/problem/B1

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

// nice problem !! -_-

        // Count all carrots with length >= x
        // Any carrot >= x will contribute at least 1 piece of length x when cut (or already is length x)
        // Count all carrots with length strictly equal to 2x
        // Cutting a carrot of length 2x with 'x' gives an extra piece of length x (2 pieces total)

void solve() {
    int n, m;   cin >> n >> m; 
    vector<int> source(n);  for(auto &val : source) cin >> val; 

    sort( whole(source));   // we need to binary search on the source 
    int answer = 0; 

    // Iterate through every possible target carrot length 'x' from 1 to m 
    for(int x = 1; x <= m; ++x) {

        // points to the first element that is greater than or equal to x
        int greater = source.end() - lower_bound(whole(source), x);     

        int twoX = upper_bound(whole(source), 2*x) - lower_bound(whole(source), 2*x); 

        answer = max(answer, greater + twoX);
    }
    cout << answer << endl;
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

