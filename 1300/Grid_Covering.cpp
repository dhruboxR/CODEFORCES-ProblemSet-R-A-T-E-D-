// https://codeforces.com/problemset/problem/2217/C

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
    int n, m, a, b;     cin >> n >> m >> a >> b;
    
    if(gcd(n,a) > 1 || gcd(m, b) > 1 || gcd(n, m) > 2) print_no;    
    else print_yes;
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

/*
A must be coprime with N  :  gcd(N,A) = 1
B must be coprime with M  :  gcd(M,B) = 1

gcd(N,M) must be at most 2 : gcd(N,M)≤2

    If gcd(N,M) = 1: there is 1 group → all cells can be visited.
    If gcd(N,M) = 2: there are 2 groups → alternation lets us visit both groups.

    If gcd(N,M) > 2: there are more than 2 groups, 
    but we can visit at most 2 of them → some cells are never reached.
*/