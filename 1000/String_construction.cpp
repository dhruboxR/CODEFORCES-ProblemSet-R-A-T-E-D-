// https://codeforces.com/contest/2250/problem/B

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
    int n, p;   cin >> n >> p; 
    int ones = n / 2, zeros = n - ones; 

    if(ones + zeros - 2 < p) {negative; return;}

    if(ones + zeros -2 == p) {
        while(ones--) cout << 1;
        while(zeros--) cout << 0;

        cout << endl;   return;
    }

    string fin = ""; 
    while(ones + zeros - 2 > p) {
        if(fin == "") {
            fin += '0'; --zeros; 
        } else {
            if(fin.back() == '1') {fin += '0'; --zeros;}
            else {fin += '1'; --ones;}
        }
    }
    
    if(ones + zeros - 2 < p) {
        if(fin.back() == '0') {
            while(zeros--) fin += '0'; 
            while(ones--) fin += '1'; 
        } else {
            while(ones--) fin += '1'; 
            while(zeros--) fin += '0'; 
        }
    }
    else {
        if(fin.back() == '0') {
            while(ones--) fin += '1'; 
            while(zeros--) fin += '0'; 
        } else {
            while(zeros--) fin += '0'; 
            while(ones--) fin += '1'; 
        }
    }

    cout << fin << endl;
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