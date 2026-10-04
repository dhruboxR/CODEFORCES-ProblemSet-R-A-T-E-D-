// https://codeforces.com/problemset/problem/2263/B

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
    The minimum score that we can make is equal to n [ diagonally ]
                        1  5  9
                        6  2  7
                        8  4  3

    And the maximum score that we can make is n + (n-1) 
                        1  2  3
                        6  5  7
                        8  4  9
    
    All that's left is construct the solution 
*/

void solve() {
    int n, k;   cin >> n >> k; 
    if(k < n || k > (2*n - 1)) {negative; return;}

    // initially we construct the matrix with maximum possible score 
    int cnt = 1; 
    vector<vector<int>> mat(n, vector<int>(n)); 

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            mat[ i ][ j ] = cnt++; 
        }
    }

    int answer = 2*n - 1; 

    if(answer == k) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) cout << mat[ i ][ j ] << " "; 
            cout << endl; 
        }
        return; 
    }
    
    // else we need to decreament the score untill it satisfies : swapping elements 
    for(int col = 1; col < n; col++) {
        int row = mat[0][col] - 1; 
        swap(mat[0][col], mat[row][col]);
        answer--; 

        if(answer == k) break; 
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << mat[ i ][ j ] << " "; 
        cout << endl; 
    }
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

