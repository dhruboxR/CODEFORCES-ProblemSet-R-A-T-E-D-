//  https://codeforces.com/contest/2248/problem/B

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
    vector<int> first(n), second(m);    

    for(auto &v : first) cin >> v;  for(auto &v : second) cin >> v; 

    if(n < 2*m) {print_no;  return;}

    sort(whole(first));     sort(whole(second));

    for(int i = 0; i < m; i++) {
        if(first[ i ] > second[ i ]) {print_no; return;}
    }
    int j = n-1; 
    for(int i = m-1; i >= 0; i--) {
        if(first[ j ] < second[ i ]) {print_no;  return;}
        j--;
    }

    print_yes;
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