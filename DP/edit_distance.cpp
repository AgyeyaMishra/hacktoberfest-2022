/* Problem Statement :

Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

*/

#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;

// Helper function to calculate the operational cost

ll fnd(string a, string b, ll i, ll j, ll n, ll m, vector<vector<ll>>& dp){
  if(i == n and j == m) return 0;
  if(i == n) return m - j;         // insert remaining elements of b in a
  if(j == m) return n - i;         // insert remaining elements of a in b

  if(dp[i][j] != -1) return dp[i][j]; // directly return already computed operation

  // if both elements are same then no need to perform any seperate operation to be make similar
  if(a[i] == b[j]) return dp[i][j] = fnd(a, b, i + 1, j + 1, n, m, dp);
  
  // All the 3 operations shall be carrried on word1 i.e. "a" in this code

  ll x = INT_MAX, y = INT_MAX, z = INT_MAX;
  x = fnd(a, b, i , j + 1, n, m, dp);         // indicating insert operation
  y = fnd(a, b, i + 1, j, n, m, dp);          // indicating deletion operation
  z = fnd(a, b, i + 1, j + 1, n, m, dp);      // indicating replace operation
  
  ll o = min({x, y, z});
  return dp[i][j] = 1 + min((ll)INT_MAX, o);  // + 1 indicates that one of the 3 operations has been performed
}

void solve() {
  string a,b;
  cin >> a >> b; // input for both strings word1 and word2
  ll n = a.length(), m = b.length();
  vector<vector<ll>> dp(n, vector<ll>(m, -1));
  cout << fnd(a, b, 0, 0, n, m, dp) << endl;
}

int main() {
  fastio();   // fast input and output in c++
  solve();
}
