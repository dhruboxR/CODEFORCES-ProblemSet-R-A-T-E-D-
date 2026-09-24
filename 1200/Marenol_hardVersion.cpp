// https://codeforces.com/problemset/problem/2254/C2

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
    int n;  cin >> n;   string a, b;    cin >> a >> b; 

    // store the indices of 1's for both strings then sum up the distance 
    // as operation moves 2 steps at a time , so move = totalSum / 2

    int move = 0; 

    for(int i = 0; i < 2; i++) {
        vector<int> idxA, idxB; 

        for(int j = i; j < n; j+=2) {
            if(a[j] == '1') idxA.push_back(j); 
            if(b[j] == '1') idxB.push_back(j); 
        }

        if(idxA.size() != idxB.size()) {negative;   return;}

        for(int j = 0; j < idxA.size(); j++) move += abs(idxA[j] - idxB[j]);
    }
    cout << move / 2 << endl;
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