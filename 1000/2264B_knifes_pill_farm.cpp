// https://codeforces.com/problemset/problem/2264/B

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
    int n, m;   cin >> n >> m; 
    multiset<int> smallest_elements; 
    
    int answer = LLONG_MIN, sum = 0;  

    for(int i = 1; i <= n; i++) {
        int value;  cin >> value; 

        if(i >= m) {
            answer = max(answer, m*value - sum); 
        }

        smallest_elements.insert(value); 
        sum += value; 

        if(smallest_elements.size() >= m) {
            sum -= *smallest_elements.rbegin();    // remove the largest element from the set 
            smallest_elements.erase( prev(smallest_elements.end()) ); 
        }
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