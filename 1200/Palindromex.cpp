// https://codeforces.com/problemset/problem/2227/D

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

void zero_bordered_palindrome(vector<int>&source, int length, int p1, int p2, int &mex) {
    set<int> temp;
    
    // if expandable outside borders
    while(p1 > 0 && p2 < length-1 && source[ p1-1 ] == source[ p2+1 ]) p1--, p2++;
    
    while( p1 < p2 ) {
        if(source[ p1 ] == source[ p2 ]) {
            temp.insert( source[ p1 ] );    
            p1++, p2--;
        } else return;      // not a palindrome 
    }
    if( p1 == p2 ) temp.insert( source[ p1 ] );
    for(int i = 0; i <= length; i++) {if( !temp.count(i) ) {mex = max(mex, i);  return;}}
}

void zero_centered_palindrome(vector<int>&source, int length, int pos, int &mex) {
    if(pos == 0 || pos == length-1) return;     // not possible to have a palindrome around it 
    
    set<int> temp;  temp.insert( 0 );

    int l = pos-1, r = pos+1;
    while( l >= 0 && r < length && source[ l ] == source[ r ] ) {
        temp.insert( source[ l ] ); l--, r++;
    }

    for(int i = 0; i <= length; i++) {if( !temp.count(i) ) {mex = max(mex, i);  return;} }
}

void solve() {
    int length;     cin >> length;   length *= 2;    vector<int> source(length);      
    int z1 = -1, z2 = -1;

    for(int i = 0; i < length; i++) {
        cin >> source[ i ]; 
        if( source[ i ] == 0) {
            if(z1 == -1) z1 = i;   
            z2 = i;
        }
    }

    int mex = 1;    // we can always have the mex as 1
    
    // palindrome where 0 is the border element and may or may not be expandable outside
    zero_bordered_palindrome(source, length, z1, z2, mex);
    
    // palindrome where 0 is the centered element
    zero_centered_palindrome(source, length, z1, mex);
    zero_centered_palindrome(source, length, z2, mex);

    cout << mex << endl; 
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