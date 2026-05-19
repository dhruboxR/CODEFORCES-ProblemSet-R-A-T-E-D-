// https://codeforces.com/problemset/problem/1703/F

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
    int length;     cin >> length;
    vector<int> index, key;

    for(int idx = 1; idx <= length; idx++) {
        int value;      cin >> value;
        if(idx > value) {
            index.push_back( idx ); key.push_back( value );
        }
    }   
    if( key.empty()) {print_zero;   return;}
    
    int pairCounter = 0;
    for(int i = index.size()-1; i > 0; i--) {
        int k = key[ i ];
        int idx = lower_bound( whole(index), k ) - index.begin();
        
        pairCounter += idx;
    }
    cout << pairCounter << endl;
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
        j > aj > i > ai || lower bound for the key, in the index !! 
*/